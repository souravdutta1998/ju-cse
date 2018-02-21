#include<stdio.h>
#include<stdlib.h>

void print_array(int *c,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d , ",c[i]);
    }
}
/**/
void booble_sort(int *c,int size){
	 int i,j,temp;
	 for(j=0;j<size;j++){
	    for(i=0;i<size-j-1;i++){
            if(c[i]>c[i+1]){
	 		    temp = c[i];
	 		    c[i]= c[i+1];
	 		    c[i+1]= temp;
            }
        }
     }
}/* takes > 0.014 sec.
void booble_sortFlag(int *c,int size){
     int i,j,tot,flag;
     for(j=0;j<size;j++){
        flag = 0;
	    for(i=0;i<size-j-1;i++){
	 		if(c[i]> c[i+1]){
                tot = c[i];
	 		    c[i]= c[i+1];
                c[i+1]= tot;
                flag = 1;
	 		}
        }
        if(!flag)
            break;
     }
}
/* takes >= 0.012 sec.*/
int main(){
    int c[]={12,1,4,65,3,11,9,34,-4,-5};
    int size = sizeof(c)/sizeof(c[0]);
    printf("The Original array is :\n\t");
    print_array(c,size);
    booble_sort(c,size);
    //booble_sortFlag(c,size);
    printf("\nThe array after sorting is :\n\t");
    print_array(c,size);
    return 0;
}

