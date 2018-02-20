#include <stdio.h>
#include <math.h>
void powerMethod(int n,float arr[n][n]); //function prototype
int main()
{
    int i,j,n;
    printf("\nEnter the order of matrix:");
    scanf("%d",&n);
    float arr[n][n];
    printf("Enter elements of matrix:-\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%f",&arr[i][j]); //input the matrix by arr[i][i] where i,j=0,1,2,3.....n-1
    powerMethod(n,arr);
    return 0;
}
void powerMethod(int n,float arr[n][n]) //function to calculate using power method
{
	int i,j,iteration=1;
	float x[n],z[n],error[n],zmax,emax;
	printf("Enter approximation:\n");
    for(i=0; i<n; i++)
    	scanf("%f",&x[i]);
    printf("Iteration\tEigenvalue\t");
    for(i=1;i<=n;i++)
    	printf("x%d\t\t",i);
    printf("error\n");
    do
    {
        for(i=0; i<n; i++)
        {
            z[i]=0;
            for(j=0; j<n; j++)
                z[i]=z[i]+arr[i][j]*x[j]; //putting the value of z[i]
        }
        zmax=fabs(z[0]);
        for(i=1; i<n; i++)
            if((fabs(z[i]))>zmax)
                zmax=fabs(z[i]); //calculating the zmax
        for(i=0; i<n; i++)
            z[i]=z[i]/zmax;
        for(i=0; i<n; i++)
        {
            error[i]=0;
            error[i]=fabs((fabs(z[i]))-(fabs(x[i]))); //keeping the errors in an array error[i]
        }
        emax=error[0];
        for(i=1; i<n; i++)
            if(error[i]>emax)
                emax=error[i];
        printf("%d\t\t%f\t",iteration,zmax);
        for(i=0;i<n;i++)
        	printf("%f\t",x[i]);
        printf("%f\n",emax);
        for(i=0; i<n; i++)
            x[i]=z[i];
        iteration++;
    }while(emax>0.0001);
    printf("\nThe required eigen value is %f",zmax);
    printf("\n\nThe required eigen vector is :\n");
    for(i=0; i<n; i++)
        printf("%f\n",z[i]);
}
