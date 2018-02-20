#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float function(float x) //the given function
{
    return 1/(1+x);
}
float simpsons(float a,float b,float precision) //function to find the value of the integral using simpson method
{

	int iteration=1; //to show the iteration 
	float x,width,h=b-a,sum0,sum1,error;
	width=h; 
	sum1=(h/6)*(function(a)+4*function((a+b)/2)+function(b)); //current sum
	printf("\n");
	printf("Iterations\tPartitions\tPrevious Sum\tCurrent Sum\tError\n");

	printf("\n");
	do
	{
		sum0=sum1; // putting the value of current sum to previous sum
		sum1=0; //making current sum zero
		width/=2;
		for(x=a;x<=b-width;x+=width)
			sum1+=function(x)+4*function(x+(width/2))+function(x+width);
		sum1=sum1*width/6;
		error=fabs(sum1-sum0);
		printf("%d\t\t%ld\t\t%f\t%f\t%f\t\n",iteration++,(long)((b-a)/width),sum0,sum1,error);
	}while(error>precision);
	printf("\n");
	return sum1;
}
int main()
{
    float lower,upper,precision,sum;
    printf("Enter the lower bound, upper bound and precision:\n");
    scanf("%f%f%f",&lower,&upper,&precision);
    sum=simpsons(lower,upper,precision);
    printf("\nValue of the integral =%f",sum);
    return 0;
}