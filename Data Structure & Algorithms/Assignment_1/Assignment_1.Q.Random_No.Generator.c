#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Max 5800

void create_array(int,int*);
int check(int,int,int*);
void insertion_sort(int*);
int main(){
    int arr[Max];
    int n,r;
    r = 5801;
    create_array(r,arr);
    return 0;
}
void create_array(int rng,int *array) {
    float x;
    char Ch_mode[Max];
    int i,y;
    for (i = 0; i < Max; i = 1 + i) {
        x = rand();
        y = (rng * x / RAND_MAX);
        while(1){
            if(check(i,y,array) == 0 && array[i] != 0 ){
                //printf("You random no. is %d\n", y);
                array[i] = y;
                break;
            }
            else{
                x = rand();
                y = (rng * x /RAND_MAX);
            }
        }
    }
    insertion_sort(array);
    for(i=0;i< Max;i++)
        printf("Number[%d] = %d\n",i+1,array[i]);
}
int check(int n,int num,int *array){
    int i;
    i= 0;
    array[n] = num;
    while(num != array[i]){
        i++;
    }
    if(i != n)
        return 1;
    else
        return 0;
}
void insertion_sort(int *ar){
    int t, k,i;
    for (i=1;i<=Max-1;i=1 + i) {
        t = ar[i];
        k = i - 1;
        while (t < ar[k]) {
            ar[k+1] = ar[k]; k = k -1;
        }
        ar[k + 1] = t;
    }
}
