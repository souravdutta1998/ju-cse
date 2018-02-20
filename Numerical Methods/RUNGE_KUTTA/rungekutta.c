#include <stdio.h>
#include <math.h>

float df(float x,float y); //function prototype
float f(float x);  //function prototype
void input(float* x0,float* y0,float* h,float* xn);  //function prototype
void Euler(float h,int n,float arr[n][4]); //function prototype
void ModifiedEuler(float h,int n,float arr[n][4]); //function prototype
void RungeKutta(float h,int n,float arr[n][4]); //function prototype
void initializeArray(float x0,float y0,float f,int n,float arr[n][4]); //function prototype
void display(int n,float arr[n][4]); //function prototype
int main()
{
	float x0,y0,h,xn;
	input(&x0,&y0,&h,&xn); //input lower bound, upper bound, h and xn
	int n=(int)(1+(xn-x0)/h);
	float arr[n][4];
	initializeArray(x0,y0,h,n,arr); //function call
	Euler(h,n,arr); //function call
	ModifiedEuler(h,n,arr); //function call
	RungeKutta(h,n,arr); //function call
	display(n,arr); //function call
	return 0;
}
void input(float* x0,float* y0,float* h,float* xn) //function to input data
{
	printf("Enter x0,y0 : ");
	scanf("%f %f",x0,y0);
	printf("Enter h : ");
	scanf("%f",h);
	printf("Enter xn : ");
	scanf("%f",xn);
}
void initializeArray(float x0,float y0,float h,int n,float arr[n][4]) //function to initialize array
{
	int i;
	arr[0][0]=x0;
	arr[0][1]=arr[0][2]=arr[0][3]=y0;
	for(i=1;i<n;i++)
		arr[i][0]=arr[i-1][0]+h;
}
float df(float x,float y) //function to return first order derivative of f
{
	return y-x;
}
float f(float x) //function to return the given eqaution
{
	return x+1-0.5*exp(x);
}
void display(int n,float arr[n][4]) //function to display tables
{
	int i;
	char ch;
	float val;
	printf("Show tables? (y/n) : "); 
	scanf(" %c",&ch);
	if(ch=='y')
	{

		printf("\nExpected Table :- \n");
		//printf("=================================================================\n");
		printf("   Iteration             x                     f(x)         \n");
		//printf("|---------------------------------------------------------------|\n");
		for(i=0;i<n;i++)
		{
			val=f(arr[i][0]);
			printf("\t%d\t\t%f\t\t%f\t\n",i,arr[i][0],val);
		}
		//printf("=================================================================\n");

		printf("\nTable for Euler Method :- \n");
		//printf("=========================================================================================\n");
		printf("   Iteration             x                 Euler f(x)                 Error        \n");
		//printf("|---------------------------------------------------------------------------------------|\n");
		for(i=0;i<n;i++)
		{
			val=f(arr[i][0]);
			printf("\t%d\t\t%f\t\t%f\t\t%f\t\n",i,arr[i][0],arr[i][1],fabs(arr[i][1]-val));
		}
		//printf("=========================================================================================\n");

		printf("\nTable for Modified Euler Method :- \n");
		//printf("=========================================================================================\n");
		printf("   Iteration             x             Modified Euler f(x)            Error        \n");
		//printf("|---------------------------------------------------------------------------------------|\n");
		for(i=0;i<n;i++)
		{
			val=f(arr[i][0]);
			printf("\t%d\t\t%f\t\t%f\t\t%f\t\n",i,arr[i][0],arr[i][2],fabs(arr[i][2]-val));
		}
		//printf("=========================================================================================\n");

		printf("\nTable for Runge Kutta Method :- \n");
		//printf("=========================================================================================\n");
		printf("   Iteration             x               Runge-Kutta f(x)             Error        \n");
		//printf("|---------------------------------------------------------------------------------------|\n");
		for(i=0;i<n;i++)
		{
			val=f(arr[i][0]);
			printf("\t%d\t\t%f\t\t%f\t\t%f\t\n",i,arr[i][0],arr[i][3],fabs(arr[i][3]-val));
		}
		//printf("=========================================================================================\n");
	}
	printf("\n");
	//printf("Expected f(%f) = %f\n",arr[n-1][0],f(arr[n-1][0]));
	printf("Using Euler's Mehod f(%f) = %f\n",arr[n-1][0],arr[n-1][1]);
	printf("Using Modified Euler's Mehod f(%f) = %f\n",arr[n-1][0],arr[n-1][2]);
	printf("Using Runge Kutta Mehod f(%f) = %f\n",arr[n-1][0],arr[n-1][3]);
}
void Euler(float h,int n,float arr[n][4]) //function to calculate solution using euler method
{
	int i;
	for(i=1;i<n;i++)
		arr[i][1]=arr[i-1][1]+h*df(arr[i-1][0],arr[i-1][1]);
}
void ModifiedEuler(float h,int n,float arr[n][4])//function to calculate solution using modified euler method
{
	int i;
	float temp;
	for(i=1;i<n;i++)
	{
		temp=df(arr[i-1][0],arr[i-1][2]);
		arr[i][2]=arr[i-1][2]+0.5*h*(df(arr[i-1][0],arr[i-1][2])+df(arr[i][0],arr[i-1][2]+h*temp));
	}
}
void RungeKutta(float h,int n,float arr[n][4]) ////function to calculate solution using runge kutta method
{
	int i;
	float temp;
	for(i=1;i<n;i++)
	{
		temp=df(arr[i-1][0],arr[i-1][3]);
		arr[i][3]=arr[i-1][3]+0.5*h*(temp+df(arr[i-1][0]+0.5*h,arr[i-1][3]+0.5*h*temp));
	}
}
