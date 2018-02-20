# include <stdio.h>
# include <math.h>

float function(float x) //the given function
{
	return exp(x)-2*x-1;
}

float function1(float x) //differentiation of the given function
{
	return exp(x)-2;
}

float function2(float x) //differentiation of the given function 
{
	return exp(x);
}
float phidash(float x) //function to check for convergence
{
	float fd=function1(x);
	return function(x)*function2(x)/fd*fd;
}

float newton_raphson(float x0)
{
	FILE * data=fopen("data.txt","w");// opening file in writing mode to store data
	float x1=x0,absolute_error0,absolute_error1=2.3,order;
	int index=1; //here index is the counter variable
	fprintf(data,"i		xi		f(xi)		abs.error		order\n"); //writing heading into the file
	fprintf(data,"%d	%.6f	%.6f\n",index++,x1,function(x1));
	do{	
		x0=x1;
		x1=x0-function(x0)/(2*function1(x0));// formula of newton rhapson method
		x1=x0-function(x0)/function1(x1);
/*		if(phidash(x1)>1){
			printf("Convergence not possible");
			exit(0);
		} */
		absolute_error0=absolute_error1;
		absolute_error1=fabs(x1-x0); //to find the absolute error
		order=log(absolute_error1)/log(absolute_error0); //calculating the order of convergence
		fprintf(data,"%d	%.6f	%.6f	%.6f	%.3f\n",index++,x1,function(x1),absolute_error1,order); //writing the data in the file
	}while(absolute_error1>0.00005);// condition for convergence
	fclose(data); // closing the file
	return x1;// returning the calculated root 
}

int main(){
	float x;
	do{
		printf("Enter assumed root :");
		scanf("%f",&x); //Enter approximate root
	}while(fabs(phidash(x))>=1); //assumed root validity check
	x=newton_raphson(x);
	printf("The root is %f ",x); //displaying the root
	return 0;
}
		
		
		
		
		
				
		
