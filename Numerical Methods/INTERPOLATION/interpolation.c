#include<stdio.h>
#include <math.h>
void input(int n,float x[n],float y[n][n],float* f); //function prototype
void createTable(int n,float x[n],float y[n][n]); //function prototype
float calculate(int n,float x[n],float y[n][n],float f); //function prototype
void displayTable(int n,float x[n],float y[n][n]); //function prototype
void difference(int n,float y[n][n]); //function prototype
float forwardInterpolation(int n,float x[n],float y[n][n],float f); //function prototype
float backwardInterpolation(int n,float x[n],float y[n][n],float f); //function prototype
float func(float n); //function prototype
int main()
{
	int i,j,n;
	printf("Enter number of records : ");
	scanf("%d",&n);
	float x[n],y[n][n],f,forward,backward,dividedDifference,fx;
	input(n,x,y,&f);
	difference(n,y);
	printf("\nTable for Forward and Backward Interpolation Method :\n");
	displayTable(n,x,y);
	forward=forwardInterpolation(n,x,y,f);
	backward=backwardInterpolation(n,x,y,f);
	createTable(n,x,y);
	printf("\nTable for Divided Difference Interpolation Method :\n");
	displayTable(n,x,y);
	dividedDifference=calculate(n,x,y,f);
	fx=func(f);
    printf("Using Newton's Forward Interpolation :\n");
    printf("f(%f) = %f\nError = %f\n",f,forward,fabs(forward-fx));
    printf("Using Newton's Backward Interpolation :\n");
    printf("f(%f) = %f\nError = %f\n",f,backward,fabs(backward-fx));
    printf("Using Newton's Divided Difference :\n");
    printf("f(%f) = %f\nError = %f\n",f,dividedDifference,fabs(dividedDifference-fx));
    return 0;
}
void input(int n,float x[n],float y[n][n],float* f) //function to input data
{
	int i;
	float interval;
	printf("Enter x0 and interval for x :");
	scanf("%f %f",&x[0],&interval);
	y[0][0]=func(x[0]);
	for(i=1;i<n;i++)
	{
		x[i]=x[i-1]+interval;
		y[i][0]=func(x[i]);
	}
	printf("Enter x for finding f(x) : ");
	scanf("%f",f);
}
void createTable(int n,float x[n],float y[n][n]) //function to create table
{
	int i,j;
	for(i=1;i<n;i++)
    	for(j=0;j<n-i;j++)
    	 	y[j][i]=(y[j+1][i-1]-y[j][i-1])/(x[j+i]-x[j]);
}
float calculate(int n,float x[n],float y[n][n],float f)
{
	int i;
	float sum=0,term=1;
    for(i=0;i<n;i++)
    {
    	sum+=(term*y[0][i]);
    	term*=(f-x[i]);
    }
    return sum;
}
void displayTable(int n,float x[n],float y[n][n]) //function to display the table
{
	int i,j;
	for(i=0;i<=n;i++)
		printf("------------------------");
	printf("-\n");
	printf("|\tx(i)\t\t||");
	for(i=0;i<n;i++)
		printf("\ty%d(i)\t\t|",i+1);
	printf("\n");
	printf("=========================");
	for(i=0;i<n;i++)
		printf("========================");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("|\t%f\t||",x[i]);
		for(j=0;j<n-i;j++)
			printf("\t%f\t|",y[i][j]);
		while(j++<n)
			printf("\t\t\t|");
		printf("\n");
	}
	for(i=0;i<=n;i++)
		printf("------------------------");
	printf("-\n");
}
void difference(int n,float y[n][n]) //function to calculate the difference
{
	int i,j;
	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	y[j][i]=y[j+1][i-1]-y[j][i-1];
}
float forwardInterpolation(int n,float x[n],float y[n][n],float f) //function to calculate using forward interpolation method
{
	int i,j;
	float h=x[1]-x[0],p=(f-x[0])/h,sum=y[0][0],term=1;
	for(i=1;i<n;i++)
	{
		term*=(p--)/i;
		sum+=term*y[0][i];
	}
	return sum;
}
float backwardInterpolation(int n,float x[n],float y[n][n],float f) //function to calculate using backward interpolation method
{
	int i,j;
	float h=x[1]-x[0],p=(f-x[n-1])/h,sum=y[n-1][0],term=1;
        for(i=1;i<n;i++)
        {
                term*=(p++)/i;
                sum+=term*y[n-i-1][i];
        }
    return sum;
}
float func(float n)
{
	return 3.14159*n*n;
}
