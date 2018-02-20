#include<stdio.h>
#include<math.h>
double function(double x) //the given function
{
	return exp(x)-2*x-1;
}
double function1(double x) //differentiation of the given function
{
	return exp(x)-2;
}
double newton_raphson(double first,int num_iteration)
{
	double second,absolute_error0,absolute_error1 =0,order;
	int index=0; //here index is the counter variable
	FILE * data=fopen("data.txt","w");
	fprintf(data,"Itr	xi	f(xi)	absolute_error	order\n");
	while(index<num_iteration)
	{
	second=first-((function(first))/function1(first));
	absolute_error1=second-first; //to find the absolute error
	if(fabs(absolute_error1)<=0.00005)
		break;
	 order=fabs(log(fabs(absolute_error1))/log(fabs(absolute_error0))); //to find the order of convergence
    absolute_error0=absolute_error1;
	fprintf(data,"%2d  %.4lf  %.4lf  %.4lf  %.4lf\n",index+1,first,function(first),fabs(absolute_error1),order);
	first=second;
	index++; //index increased by one
	}
}
int main()
{
	double first;
	int num_iteration;
	printf("Enter the first root: \n");
	scanf("%lf",&first);
	printf("Enter the number of iteration: \n");
	scanf("%d",&num_iteration);
	newton_raphson(first,num_iteration);
	return 0;
}
