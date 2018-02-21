#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int partition(int array[],int start,int end){
    int i,pivot,p_index,temp;
    pivot = array[end];     //fixing the pivot point to last member of close bound array.
    p_index = start;            //traversing the p_index.
    for(i=start;i<end;i++){
        if(array[i] <= pivot){      //if element on the left side is less than pivot.
            temp = array[i];            //swapping it with element stored at p_index term.
            array[i] = array[p_index];
            array[p_index] = temp;
            p_index = p_index+1;            //and now incrementing the p_index value.
        }
    }
    int swap;
    swap = array[p_index];
    array[p_index] = array[end];
    array[end] = swap;
    return p_index;
}
void quick_sort(int array[],int start,int end){
        if(start>=end){             //basic condition for terminating the recursion.
                return;
        }
        int p_index = partition(array,start,end);        //getting the partition index in recursive manner.
        quick_sort(array,start,p_index-1);              //new sets of bound set up for quick_sort.
        quick_sort(array,p_index+1,end);

}
int main(){
    int i,n;
    //printf("Enter the no.of element of your array:\n");
    //scanf("%d",&n);
    int array[]= {7,1,11,6,800,5,31,41};
    n = sizeof(array)/sizeof(array[0]);
    /*printf("Enter the array' element:\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }*/
    quick_sort(array,0,n-1);        //first call of quick_sort function.
    printf("Your sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    return 0;
}
