#include<stdio.h>
#define max 15

extern int avail;

struct s{
    int rowNo;
    int colNo;
    double value;
};
struct s sparse[max];
struct m{
    struct s sparse[max];
    int rw;
    int clm;
    int non0val;
};
struct m matrix[max];
int avail = 1;
void read_spar(int index,int r,int c){
    int i,j,k=0;
    while(1){
        matrix[index].rw = r;
        matrix[index].clm = c;
        printf("Enter the value of row(less or equal than %d) and column(less or equal than %d) index:\n",r,c);
        scanf("%d %d",&i,&j);
        if(i != 0 && j!= 0){
            matrix[index].sparse[k].rowNo = i-1;
            matrix[index].sparse[k].colNo = j-1;
            printf("Enter the non-zero value at this indices:\n");
            scanf("%lf",&matrix[index].sparse[k].value);
            k++;
        }
        else{
            break;
        }
    }
    matrix[index].non0val = k;
    avail++;
}
void print_spar(int index){
    int i,j,k;
    float array[matrix[index].rw][matrix[index].clm];
    for(i=0 ;i < (matrix[index].rw);i++){
        for(j=0 ;j < (matrix[index].clm);j++){
            array[i][j] = 0;
        }
    }
    for(k=0 ;k < (matrix[index].non0val);k++){
        for(i=0 ;i < (matrix[index].rw);i++){
            if(i == matrix[index].sparse[k].rowNo){
                for(j=0 ;j < (matrix[index].clm);j++){
                    if(j == matrix[index].sparse[k].colNo){
                        array[i][j] = matrix[index].sparse[k].value;
                    }
                }
            }
            else{
                continue;
            }
        }
    }

    for(i=0;i<(matrix[index].rw);i++){
        for(j=0;j<(matrix[index].clm);j++){
            printf(" %lf\t",array[i][j]);
        }
        printf("\n");
    }
}

void mult_spar_const(int index,double cons){
    int i,j,k;
    int a = 0;
    for(k=0;k<matrix[index].non0val;k++){
        for(i=0;i<matrix[index].rw;i++){
            for(j=0;j<matrix[index].clm;j++){
                if(j == matrix[index].sparse[k].colNo && i == matrix[index].sparse[k].rowNo){
                matrix[avail].sparse[a].value = cons * matrix[index].sparse[k].value;
                matrix[avail].sparse[a].colNo = matrix[index].sparse[k].colNo;
                matrix[avail].sparse[a].rowNo = matrix[index].sparse[k].rowNo;
                a++;
                }
            }
        }
    }
    matrix[avail].non0val = a;
    matrix[avail].clm = matrix[index].clm;
    matrix[avail].rw = matrix[index].rw;
    printf("The new sparse matrix is:\n");
    print_spar(avail);

    avail++;
}
void add_spar(int index1,int index2){
    int i,j,k;
    float array1[matrix[index1].rw][matrix[index1].clm];
    float array2[matrix[index2].rw][matrix[index2].clm];

    for(i=0 ;i < (matrix[index1].rw);i++){
        for(j=0 ;j < (matrix[index1].clm);j++){
            array1[i][j] = 0;
        }
    }
    for(i=0 ;i < (matrix[index2].rw);i++){
        for(j=0 ;j < (matrix[index2].clm);j++){
            array2[i][j] = 0;
        }
    }

    if(matrix[index1].rw == matrix[index2].rw && matrix[index1].clm == matrix[index2].clm){
        float farray[matrix[index1].rw][matrix[index2].clm];
        for(k = 0;k < (matrix[index1].non0val);k++){
            for(i = 0;i < (matrix[index1].rw);i++){
                if(i == matrix[index1].sparse[k].rowNo){
                    for(j = 0;j < (matrix[index1].clm);j++){
                        if(j == matrix[index1].sparse[k].colNo){
                            array1[i][j] = matrix[index1].sparse[k].value;
                        }
                    }
                }
                else{
                    continue;
                }
            }
        }
        for(k = 0;k < (matrix[index2].non0val);k++){
            for(i = 0;i < (matrix[index2].rw);i++){
                if(i == matrix[index2].sparse[k].rowNo){
                    for(j = 0;j < (matrix[index2].clm);j++){
                        if(j == matrix[index2].sparse[k].colNo){
                            array2[i][j] = matrix[index2].sparse[k].value;
                        }
                    }
                }
                else{
                    continue;
                }
            }
        }
        for(i=0;i<matrix[index1].rw;i++){
            for(j=0;j<matrix[index2].clm;j++){
                farray[i][j] = array1[i][j] + array2[i][j];
            }
        }
        int k =0;
        printf("The new sparse matrix is:\n");
        for(i=0;i<matrix[index1].rw;i++){
            for(j=0;j<matrix[index2].clm;j++){
                printf("%lf\t",farray[i][j]);
                if(farray[i][j] ){
                    matrix[avail].sparse[k].rowNo = i;
                    matrix[avail].sparse[k].colNo = j;
                    matrix[avail].sparse[k].value = farray[i][j];
                    k++;
                }
                else{
                    continue;
                }
            }
            printf("\n");
        }
        matrix[avail].non0val = k;
        matrix[avail].rw = matrix[index1].rw;
        matrix[avail].clm = matrix[index2].clm;

        avail++;
    }
    else{
        printf("Addition is not possible as dimension is not same(%d * %d) ! = (%d * %d)\n",matrix[index1].rw,matrix[index1].clm,matrix[index2].rw,matrix[index2].clm);
    }

}
void trans_spar(int index){
    int i,j,k;
    int a = 0;
    for(k=0;k<matrix[index].non0val;k++){
        for(i=0;i<matrix[index].rw;i++){
            for(j=0;j<matrix[index].clm;j++){
                if(j == matrix[index].sparse[k].colNo && i == matrix[index].sparse[k].rowNo){
                    matrix[avail].sparse[a].value = matrix[index].sparse[k].value;
                    matrix[avail].sparse[a].colNo = matrix[index].sparse[k].rowNo;
                    matrix[avail].sparse[a].rowNo = matrix[index].sparse[k].colNo;
                    a++;
                }
            }
        }
    }
    matrix[avail].non0val = a;
    matrix[avail].clm = matrix[index].rw;
    matrix[avail].rw = matrix[index].clm;
    printf("The transpose of your sparse matrix is:\n");
    print_spar(avail);

    avail++;
}

void mult_spar(int index1,int index2){
    int i,j,k;
    float array1[matrix[index1].rw][matrix[index1].clm];
    float array2[matrix[index2].rw][matrix[index2].clm];

    for(i=0 ;i < (matrix[index1].rw);i++){
        for(j=0 ;j < (matrix[index1].clm);j++){
            array1[i][j] = 0;
        }
    }
    for(i=0 ;i < (matrix[index2].rw);i++){
        for(j=0 ;j < (matrix[index2].clm);j++){
            array2[i][j] = 0;
        }
    }

    for(k=0 ;k < (matrix[index1].non0val);k++){
        for(i=0 ;i < (matrix[index1].rw);i++){
            if(i == matrix[index1].sparse[k].rowNo){
                for(j=0 ;j < (matrix[index1].clm);j++){
                    if(j==matrix[index1].sparse[k].colNo){
                        array1[i][j] = matrix[index1].sparse[k].value;
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    for(k=0 ;k < (matrix[index2].non0val);k++){
        for(i=0 ;i < (matrix[index2].rw);i++){
            if(i == matrix[index2].sparse[k].rowNo){
                for(j=0 ;j < (matrix[index2].clm);j++){
                    if(j==matrix[index2].sparse[k].colNo){
                        array2[i][j] = matrix[index2].sparse[k].value;
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    float farray[matrix[index1].rw][matrix[index2].clm];
    if(matrix[index1].clm == matrix[index2].rw){
        for(i=0;i<(matrix[index1].rw);i++){
            for(j=0;j<(matrix[index2].clm);j++){
                int sum = 0;
                for(k=0;k<(matrix[index1].clm);k++){
                    sum += array1[i][k]*array2[k][j];
                }
                farray[i][j] = sum;
            }
        }
    }
    else{
        printf("Multiplication is not possible as column of 1st matrix(%d) is not equal to row of 2nd matrix(%d)",matrix[index1].rw,matrix[index2].clm);
    }
    k =0;
    for(i=0;i<matrix[index1].rw;i++){
        for(j=0;j<matrix[index2].clm;j++){
            if(farray[i][j] != 0){
                matrix[avail].sparse[k].rowNo = i;
                matrix[avail].sparse[k].colNo = j;
                matrix[avail].sparse[k].value = farray[i][j];
                k++;
            }
            else{
                continue;
            }
        }
    }
    matrix[avail].non0val = k;
    matrix[avail].rw = matrix[index1].rw;
    matrix[avail].clm = matrix[index2].clm;

    printf("The new sparse matrix is:\n");
    print_spar(avail);
    if(matrix[index1].clm == matrix[index2].rw)
    avail++;

}
int main(){
    int choice;
    while(1){
        // printing the options
        printf("\nCurrent index(starts with 1) = %d\n",avail);
        printf("1. Enter a sparse matrix\n");
        printf("2. Print a sparse matrix\n");
        printf("3. Multiply a sparse matrix with a constant\n");
        printf("4. Add two sparse matrix\n");
        printf("5. Transpose the sparse matrix\n");
        printf("6. Multiply two sparse matrix\n");
        printf("Enter  -1 to exit:\n ");
        printf("\n Enter the choice:\n");
        scanf("%d",&choice);

        switch(choice){

            case 1: {
                int row,column;
                printf("Give the dimension of sparse matrix(1st row no.):\n");
                scanf("%d %d",&row,&column);
         		printf("Set the value 0 to terminate.\n");
                read_spar(avail,row,column);
                break;
            }
            case 2: {
                printf("Enter the sparse index: ");
                int index;
                scanf("%d", &index);
                printf("Your sparse matrix:\n");
                print_spar(index);
                break;
	       }
            case 3: {
                printf("Enter the sparse index and the constant respectively: ");
                int index;
                double k;
                scanf("%d %lf", &index, &k);
                mult_spar_const(index, k);
                break;
            }

            case 4: {
                int index1, index2;
                printf("Enter the index of 1st polynomial: ");
                scanf("%d", &index1);
                printf("Enter the index of 2nd polynomial: ");
                scanf("%d", &index2);
                add_spar(index1, index2);
                break;
            }
            case 5: {
                printf("Enter the sparse index: ");
                int index;
                scanf("%d",&index);
                trans_spar(index);
                break;
            }
            case 6: {
                int index1,index2;
                printf("Give the indexes of sparse matrix:\n");
                scanf("%d %d",&index1,&index2);
                mult_spar(index1,index2);
                break;
            }
       }
       if(choice == -1){
            break;
       }
    }
    return 0;
}
