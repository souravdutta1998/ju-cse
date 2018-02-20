#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(double **matrix, int size) //function to print the matrix in the form of equations
{  
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++) 
		{
		    if(j!=size-1)
		printf("(%2.2lf) x%d  + ",matrix[i][j],i+1); 
		else
		printf("(%2.2lf) x%d",matrix[i][j],i+1);
		}
		printf(" =  %2.2lf\n",matrix[i][size]); //printing the RHS of the equations
	}
}

int finding_pivot(double **matrix,int indx,int n) //function to  get the partial pivot (the maximum value in each column)
{ 
	int row,pivot=indx;
	double max=fabs(matrix[indx][indx]);
	for(row=indx+1;row<n;row++){
		if(fabs(matrix[row][indx])>max){ //row containing the largest element is selected as pivot
			max=matrix[row][indx];
			pivot=row;
		}
	}
	return pivot;
}

void swap_rows(double **p2Row1,double **p2Row2)
{ // function to swap pivotal row & current row
	double *temp=*p2Row1; // pointers pointing to respective rows are swapped 
	*p2Row1=*p2Row2;
	*p2Row2=temp;
}

void gaussian_elimination(double **matrix, int n, int curIndx) //using gaussian elimination method, to find the upper triangular matrix
{ 
	if(curIndx==n-1){// reached last row of augmented matrix so no more elimination is possible
		printf("The elimination is completed\n");
	}
	else{
		printf("\nSTEP %d:\n\n",curIndx+1);
		int row,col;
		int pivot=finding_pivot(matrix,curIndx,n); // finding the pivot row(row having maximum element in the current column)
		double multiplier;
		if(pivot!=curIndx){
			printf("Swapping row %d and %d\n",curIndx,pivot);
			swap_rows(&matrix[pivot],&matrix[curIndx]); //we are swapping two rows when pivot (max) is found
		}
		for(row=curIndx+1;row<n;row++){
			multiplier=matrix[row][curIndx]/matrix[curIndx][curIndx];// generating the multiplier for each row below the current row
			printf("row %d --> row %d -(%lf)*row %d\n",row,row,multiplier,curIndx);
			for(col=curIndx;col<n+1;col++){
				matrix[row][col]-=multiplier*matrix[curIndx][col];// eliminating the column elements with the transformation Rj=Rj-mj*Ri;i<j<n
			}
		}
		printf("Equations after Step %d :\n",curIndx+1);
		print_matrix(matrix,n); //printing the matrix in the form of equations

		gaussian_elimination(matrix,n,curIndx+1); //recursive call to the function to eliminate next column elements
	}

}

void backsubstitution(double **M, double *X, int n) //function for performing back substitution
{
	int i,j;
	double sum;
	X[n-1]=M[n-1][n]/M[n-1][n-1];
	for(i=n-2;i>=0;i--){
		sum=0;
		for(j=i+1;j<n;j++) sum+=X[j]*M[i][j];
		X[i]=(M[i][n]-sum)/M[i][i];
	}
}

int main()
{
	int size,i,j;
	double **matrix,*roots;
	printf("Enter Order of matrix: ");
	scanf("%d",&size);
	matrix=(double **)(malloc(size*sizeof(int *)));
	for(i=0;i<size;i++) matrix[i]=(double *)(malloc((size+1)*sizeof(double))); //allocating the space for matrix in heap
	printf("Enter the elements of augmented matrix row-wise:\n");
	for(i=0;i<size;i++){
		for(j=0;j<size+1;j++) scanf("%lf",&matrix[i][j]);
	}
	printf("The given set of equations are :\n");
	print_matrix(matrix,size);
	gaussian_elimination(matrix,size,0);
	roots=(double *)(malloc(size*sizeof(double)));
	backsubstitution(matrix,roots,size);
	printf("The Roots Of the Given Set of Equation are :\n");
	for(i=0;i<size;i++) printf("x%d = %2.2lf\n",i+1,roots[i]);
	for(i=0;i<size;i++) free(matrix[i]);
	free(matrix);
	free(roots);
	return 0;
}