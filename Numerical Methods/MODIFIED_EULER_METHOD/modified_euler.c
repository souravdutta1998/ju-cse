#include<stdio.h>
#include<math.h>

float f(float a,float b){   //function for first order derivative at a and b
    float result = 0.0;
    result = 2*((a*a)+b); 
    return result;
}
float Y(float a){ //the given function
    float result = 0.0;
    result = 1.5*exp(2*a)-(a*a)-a-0.5;
    return result;
}
int main(){
    float x,y1,y,y00,h;
    x = 0; y = 1; h = 0.1;
    printf("\tMODIFIED EULER METHOD\n");
    printf("The given differential equation : dy/dx = 2*(x^2+y)\n");
    printf("The actual Equation y = 1.5*exp(2*x)-x^2-x-0.5\n");
    
    printf("x\t\tycomputed\tyactual\t\tAbs.error\n");
   
    y00 = y + h*f(x,y);
    y1 = y + (f(x,y)+f(x+h,y00))/2*h;    //formula for Modified Euler's Method.
    									 //In this case final slope will be the average of f(x,y) and f(x+h,y)
                                            
    x += h;
    printf("%f\t%f\t%f\t%f\n",x,y1,Y(x),fabs(Y(x)-y1));
    
    int i = 1;
    do{
        y = y1;
        y00 = y + h*f(x,y);
        y1 = y + (f(x,y)+f(x+h,y00))/2*h;
        x += h;
        printf("%f\t%f\t%f\t%f\n",x,y1,Y(x),fabs(Y(x)-y1));
        
        i++;
    }
    while(x <= 1);      //condition for termination of loop
    return 0;
}