#include<stdio.h>
#include<math.h>
#define E 0.000005
double Gfunction(double x) //function in terms of x
{
    return sqrt(exp(x)/4);
}
double Gdiff(double x) //first derivative of Gfunction
{
    return (exp(x/2)/4);
}
double Ffunction(double x) //the given function
{
    return exp(x)-4*x*x;
}
double fixed_point(double first,int num_iteration) 
{
 double second1,second2,absolute_error0,absolute_error1=0,order;
 int index=0; //here index is the counter variable
 second1=Gfunction(first);
 FILE * data=fopen("data.txt","w");
 //printf("i xi |g'(xi)| f(xi) absolute_error Order_convergence\n");
 fprintf(data,"Itr \t xi \t |g'(xi)| \t f(xi) \t absolute_error \t order\n");
 while(index<num_iteration)
 {
     second2=Gfunction(second1);
     absolute_error1=second2-second1; //to find absolute error
     if(fabs(absolute_error1)<=E)
        break;
    order=log(fabs(absolute_error0))/log(fabs(absolute_error1));
    absolute_error0=absolute_error1; //to find the order of convergence
     fprintf(data,"%2d %.6lf %.6lf %.6lf %.6lf %.6lf\n",index+1,second1,fabs(Gdiff(second1)),Ffunction(second1),fabs(absolute_error1),order); //output is saved in the .txt file
     second1=second2; 
     index++; //index increased by one
 }

}
int main()
{
    double first;
    int num_iteration;
    printf("Enter the first approximate root\n");
    scanf("%lf",&first);
    while(fabs(Gdiff(first))>1)
    {
    	printf("Enter the first approximate root\n");
    	scanf("%lf",&first);
    }
    printf("Enter the total no. of iteration\n");
    scanf("%d",&num_iteration);
    fixed_point(first,num_iteration);
    return 0;
}
