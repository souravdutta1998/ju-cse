#include<stdio.h>
#include<math.h>

int n;
double x_i(double array[n][n+1],int index,double x[]){    //function for returning the x[index] value to the main.
    double result0,sum=0.0;
    int i;
    for(i=0;i<n;i++){
        if(i != index){
            sum += array[index][i]*x[i];       /*summation of negative part in x[index] = (array[index][n]-(sum of array[index][j]+....+))/array[index][index].
                                                j < n and j != index.*/
        }
    }
    result0 = (array[index][n]-sum)/array[index][index];
    return result0;
}

double max(double a,double b,double c){     //function for finding the maximum of three errors
    if(a>=b && (a>c || b>=c))
        return a;
    if(b>=c && (b>a || a>=c))
        return b;
    if(c>=a && (c>b || a>=b))
        return c;
}

int main(){
    int i,j;
    printf("Enter the order of the augmented matrix\n");
    scanf("%d",&n);   
    double m[][4]={{5,-1,1,10},{2,8,-1,11},{-1,1,4,3}};
    printf("Enter the augmented matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            scanf("%lf",&m[i][j]);      //input the coefficients of matrix
        }
    }
    
    printf("The given equations are:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            if(j == n-1)
                printf(" (%f) x%d ",m[i][j],j+1);
            else if(j == n)
                printf(" = %f",m[i][j]);
            else
                printf("(%f) x%d + ",m[i][j],j+1);

        }
        printf("\n");
    }
    double x[n],X[n],error[n];
    for(j=0;j<3;j++){
            X[j] = 0;       //Initialization of x[i] with 0 value.
        }
    i = 0;
    printf("\nIteration\tx1\t\tx2\t\tx3\t\tmax(xi(k)-xi(k-1))\n");
    do{
        for(j=0;j<n;j++){
            x[j] = X[j];
        }
        for(j=0;j<n;j++){
            X[j] = x_i(m,j,x);
            error[j] = X[j]-x[j];            //keeping the errors in an array
            x[j]=X[j];
        }
        printf("\t%d\t%lf\t%lf\t%lf\t%lf\n",i++,X[0],X[1],X[2],max(fabs(error[0]),fabs(error[1]),fabs(error[2])));
    }
    while(fabs(error[0]) >= 0.001 && fabs(error[1]) >= 0.001 && fabs(error[2]) >= 0.001);

    /*Printing the final Answer.*/
    printf("\nThe calculated roots are:\n");
    for(i=0;i<n;i++)
        printf("\tx%d = %lf\n",i+1,X[i]);
    return 0;
}