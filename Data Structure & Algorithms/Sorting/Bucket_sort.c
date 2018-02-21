#include<stdio.h>

void bucket_sort(int array[],int n,int max){
    //int size = max;
    int i,j,k,bucket[max+1];
    for(i=0;i<=max;i++){
        bucket[i] = 0;
    }
    for(i=0;i<n;i++){
        bucket[array[i]] = bucket[array[i]] + 1;
    }
    i = 0;
    for(j=0;j<=max;j++){
        if(bucket[j] != 0){
            for(k=bucket[j];k>0;k--){
                array[i++] = j;
            }
        }
    }
}
int main(){
    int i,n;
    printf("Enter the no. of element of array u want to sort:\n");
    scanf("%d",&n);
    int big,array[n];
    printf("Enter the element of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    big = 0;
    for(i=0;i<n;i++){
        if(array[i]>big)
            big = array[i];
    }
    bucket_sort(array,n,big);
    printf("The element of array after the sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}
