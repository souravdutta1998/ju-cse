#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float function(float x) //the given function
{
    return 1/(1+x);
}
float trapezoidal(float a,float b,float precision) //function to find the value of the integral using trapezoidal method
{
    int iteration=1; //to show the iteration 
    float x,h=b-a,term=(function(a)+function(b))/2,sum0,sum1,err;
    sum1=h*term; //current sum
    printf("Iteration\tInterval\tPrevious_sum\tCurrent_sum\tError\n");
    do{
        sum0=sum1; // putting the value of current sum to previous sum
        sum1=0; //making current sum zero
        h/=2;
        for(x=a+h;x<b;x+=h)
            sum1+=function(x);
        sum1+=term;
        sum1*=h;
        err=fabs(sum1-sum0);
        printf("%d\t\t%ld\t\t%f\t%f\t%f\n",iteration++,(long)((b-a)/h),sum0,sum1,err);
    }while(err>precision);
    return sum1;
}
int main()
{
    float lower,upper,precision,sum;
    printf("Enter the lower bound, upper bound and precision:\n");
    scanf("%f%f%f",&lower,&upper,&precision);
    sum=trapezoidal(lower,upper,precision);
    printf("\nValue of integral= %f",sum);
    return 0;
}

