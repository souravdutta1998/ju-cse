#include<stdio.h>
#include<stdlib.h>

void sort(int array[],int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j = i+1;j<n;j++){
            if(array[j]<array[min])
                min = j;
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void merge_sort(int array[],int n){
    int x = n/2; int y = n-n/2;
    int i,j,k,l[x],r[y];
    k = 0;
    for(i=0;i<x;i++){
        l[i] = array[k++];
    }
    for(i=0;i<y;i++){
        r[i] = array[k++];
    }
    sort(l,x);
    sort(r,y);
    j = k = i = 0;
    while(j < x && k < y){
        if(l[j] <= r[k]){
            array[i++] = l[j++];
        }
        else if(l[j] > r[k]){
            array[i++] = r[k++];
        }
    }
    if(j<x){
        array[i++] = l[j];
    }
    if(k<y){
        array[i++] = r[k];
    }
}
int main(){
    int n,i;
    printf("Enter the no. of element of array u want to sort:\n");
    scanf("%d",&n);
    int array[n];// ={2,5,1,7,3,8,9};
    printf("Enter the element of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    merge_sort(array,n);
    printf("The element of array after the sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}
