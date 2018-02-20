#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void input(int n,float original_matrix[n][n],float duplicate[n][n],float inverse[n][n]);
void gauss_jordan(int n,float original_matrix[n][n],float inverse[n][n]);
void multiply_matrix_matrix(int n,float duplicate[n][n],float inverse[n][n],float multiplied[n][n]);
void print_dual_matrix(int n,float original_matrix[n][n],float inverse[n][n]);
void print(int n,float matrix[n][n]);
int main()
{
	int n,p,q;
	printf("Enter order of the matrix:\n");
	scanf("%d",&n);
	float duplicate[n][n],original_matrix[n][n],inverse[n][n],multiplied[n][n];
	input(n,original_matrix,duplicate,inverse);
	gauss_jordan(n,original_matrix,inverse);
	multiply_matrix(n,duplicate,inverse,multiplied);
	printf("The given matrix is:\n");
	print(n,duplicate);
	printf("\n\nInverse of the given matrix is:\n");
	print(n,inverse);
	printf("\n\nAfter multiplying the given matrix with its inverse:\n");
	print(n,multiplied);

    return 0;
}
void input(int n,float original_matrix[n][n],float duplicate[n][n],float inverse[n][n]) //function to input the elements of matrix
{
    int i,j;
    printf("Enter the elements of matrix row-wise:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%f",&original_matrix[i][j]);
            duplicate[i][j]=original_matrix[i][j];
            if(i==j)
                inverse[i][j]=1;
            else
                inverse[i][j]=0;
        }
    }
}
void multiply_matrix(int n,float duplicate[n][n],float inverse[n][n],float multiplied[n][n]) //function to multiply two matrices
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            multiplied[i][j]=0;
            for(k=0;k<n;k++)
                multiplied[i][j]+=duplicate[i][k]*inverse[k][j];
        }
    }
}
void print(int n,float a[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %f ",a[i][j]);
        }
        printf("\n");
    }
}
void gauss_jordan(int n,float original_matrix[n][n],float inverse[n][n]) //function to find the inverse using gauss jordan method
{
        int i,j,k;
        float temp;
        for(i=0;i<n;i++)
        {
            if(!original_matrix[i][j]) //if condition satisfies print error and exit
            {
            printf("This method cannot be executed\n");
			exit(1);
            }
            printf("Dual Matrix after each step: \n"); 
            print_dual_matrix(n,original_matrix,inverse);//printing the dual matrix after first step
            if(original_matrix[i][i]!=1)
            {
                temp=original_matrix[i][i];
                for(j=n-1;j>=0;j--)
                {
                    inverse[i][j]/=temp;
                    original_matrix[i][j]/=temp;
                }
                 printf("Dual Matrix after each step: \n");
                print_dual_matrix(n,original_matrix,inverse);
            }
            for(j=i+1;j<n;j++)
            {
                temp=original_matrix[j][i];
                for(k=0;k<n;k++)
                {
                    original_matrix[j][k]-=temp*original_matrix[i][k];
                    inverse[j][k]-=temp*inverse[i][k];
                }
            }
             printf("Dual Matrix after each step: \n");
                print_dual_matrix(n,original_matrix,inverse);
            for(j=i-1;j>=0;j--)
            {
                temp=original_matrix[j][i];
                for(k=0;k<n;k++)
                {
                     original_matrix[j][k]-=temp*original_matrix[i][k];
                    inverse[j][k]-=temp*inverse[i][k];
                }
            }
        }
         printf("Dual Matrix after each step: \n");
        print_dual_matrix(n,original_matrix,inverse);
}
void print_dual_matrix(int n,float original_matrix[n][n],float inverse[n][n]) //printing the dual matrix
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %f | %f\t",original_matrix[i][j],inverse[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

