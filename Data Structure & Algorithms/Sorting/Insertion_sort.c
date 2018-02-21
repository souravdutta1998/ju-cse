#include<stdio.h>
#include<stdlib.h>

void print_array(int *c,int size){
    int i;
    for(i=0;i<size-1;i++){
        printf("%d , ",c[i]);
    }
    printf("%d.",c[i]);
}
/**/
void insertion_sort(int *c,int size){
	 int i,j,temp;
	 for(j=0;j<size;j++){
	    for(i=j+1;i<size;i++){
            if(c[i] < c[j] && i > j){
	 		    temp = c[i];
	 		    c[i]= c[j];
	 		    c[j]= temp;
            }
        }
     }
}
/*time >= 0.012sec*/
int main(){
    int c[]={12,1,4,65,3,11,9,34,-4,-5};
    int size = sizeof(c)/sizeof(c[0]);
    printf("The Original array is :\n\t");
    print_array(c,size);
    insertion_sort(c,size);
    printf("\nThe array after sorting is :\n\t");
    print_array(c,size);
    return 0;
}

