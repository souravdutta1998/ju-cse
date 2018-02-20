#include<stdio.h>
#include<math.h>
double function(double x) // the given function
{
	return exp(x)-2*x-1;
}
double function1(double x) //first derivative of given function
{
	return exp(x)-2;
}
double function2(double x) //second derivative of given function
{
	return exp(x);
}
double convergence_condition(double x) //conditon for the convergence
{
	return (fabs(function(x)*function2(x)))/(function1(x)*function1(x));
}
double secant(double x0,double x1) //finding root of function using secant method
{
	double x2,absolute_error0,absolute_error1=0,order;
	int index=1;
	FILE *data=fopen("data.txt","w"); //opening and writing a data text file named data.txt
	fprintf(data,"itr\t x0\t x1\t x2\t f(x2)\t abs_error\t order\n");
	do{
		x2= x1-(((x1-x0)*function(x1))/(function(x1)-function(x0)));
		fprintf(data,"%d  %.6f  %.6f  %.6f  %.6f  %.6f  %.6f\n",index,x0,x1,x2,function(x2),absolute_error1,order); //output is saved in the .txt file
		absolute_error0 = fabs(x1-x0);
		absolute_error1 = fabs(x2-x1);
		order=log(absolute_error1)/log(absolute_error0); //calculating the order of convergence
		x0=x1;
		x1=x2;
		index++; //index increased by one
	}while(fabs(absolute_error0)>0.000005);
	fclose(data); //closing the data file
	return x0; //returning  the final root
}
int main()
{
	double first,second;
	 do
    {
    	printf("Enter the two approximate root\n");
    	scanf("%lf %lf",&first,&second);
    }while(convergence_condition(first)>=1 || convergence_condition(second)>=1); //condition for the convergence
	printf("Final root is %lf\n",secant(first,second));	
	
}

