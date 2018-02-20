#include<stdio.h>
#include<math.h>

float f(float a,float b){       //function for first order derivative at a and b
    float result = 0.0;
    result = 2*((a*a)+b);
    return result;
}
float Y(float a){
    float result = 0.0;
    result = 1.5*exp(2*a)-(a*a)-a-0.5;      //the given function
    return result;
}
int main(){
    float x,y,h;
    x = 0; y = 1; h = 0.1;
    printf("\tEULER METHOD\n");
    printf("The given differential equation : dy/dx = 2*(x^2+y)\n");
    printf("The actual Equation y = 1.5*exp(2*x)-x^2-x-0.5\n");
    printf("x\t\tycomputed\tyactual\t\tAbs.error\n");
   
    y += f(x,y)*h;                                  //Euler iterative Formula
    printf("%f\t%f\t%f\t%f\n",x,y,Y(x),fabs(Y(x)-y));
    int i = 1;
    do{
        x += h;
        y += f(x,y)*h;
        printf("%f\t%f\t%f\t%f\n",x,y,Y(x),fabs(Y(x)-y));
        i++;
    }
    while(x <= 1);      //condition for termination of loop
    return 0;
}
