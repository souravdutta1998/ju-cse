#include<stdio.h>
#include<math.h>

double Ffunction(double x) //the given function
{
double y;
y=exp(x)-4*x*x;
return y;
}

double Gfunction(double x) //function in terms of x
{
double y;
y=sqrt(exp(x)/4);
return y;
}

double mod(double x) //function to find out the mod of value
{
if(x<0)
 {
  x=x*-1;
 }
return x;
}

double aitken(double x) //function for finding out the root using aitken method
{
int index=1; //here index is the counter variable
double x_i1=0,x_i2=0,x_i3=0,absolute_error0=0,absolute_error1=0,order=0;
FILE *data = fopen("aitken.txt","w"); //opening and writing a data text file named data.txt
x_i1=x;
x_i2=Gfunction(x_i1); //finding out the next approx roots
x_i3=Gfunction(x_i2);
absolute_error1=mod(x_i1-x_i2); //to find absolute error
absolute_error0=mod(x_i1-x_i3);
order=log(absolute_error1)/log(absolute_error0); //calculating the order of convergence
fprintf(data,"index	f(xi1)		xi1		xi2		xi3		a_error		order");
fprintf(data,"\n%d	%lf	%lf	%lf	%lf	%lf	%lf",index,Ffunction(x_i1),x_i1,x_i2,x_i3,absolute_error1,order); //output is saved in the .txt file

while(mod((x_i1-x_i2))>=0.000001 && index<50)
 {
  x_i1=x_i3-(((x_i3-x_i2)*(x_i3-x_i2))/(x_i3-(2*x_i2)+x_i1));
  x_i2=Gfunction(x_i1);
  x_i3=Gfunction(x_i2);
  absolute_error1=mod(x_i1-x_i2);
  order=mod(log(absolute_error1)/log(absolute_error0));
  index++; //index increased by one
  fprintf(data,"\n%d	%lf	%lf	%lf	%lf	%lf	%lf",index,Ffunction(x_i1),x_i1,x_i2,x_i3,absolute_error1,order); //output is saved in the .txt file
 
  absolute_error0=absolute_error1;
 }
fclose(data); //closing the data file
return x_i1; //returning  the final root
}

int main()
{
double x;

printf("Enter the first approximate root: ");
scanf("%lf",&x);
printf("\nx= %lf \n",aitken(x));
return 0;
}
