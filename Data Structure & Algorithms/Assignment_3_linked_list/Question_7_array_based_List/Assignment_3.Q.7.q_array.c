#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int info;
    int next;
};
struct List{                     //structure of linked list in form of array.
    int size;
    struct node *array;
};

struct List *create_list(int V){                //creating a List of array size V;
    struct List *newlist = (struct List*)malloc(sizeof(struct List));
    newlist->size = -1;
    newlist->array = (struct node*)malloc(V*sizeof(struct node));
    return newlist;
}

void insert(struct List *l,int data){           //function for inserting key.
    l->array[l->size+1].info = data;
    if(l->size == -1)
       l->array[l->size+1].next = -1;
    else
        l->array[l->size+1].next = l->array[l->size].info;     /*storing the next info of
                                                            previous info in next field of current List array.*/
    l->size++;              //incrementing the list size by 1.
}

void print_list(struct List *l){        //function to print the list.
    if(l->size == -1){              //case of an empty list.

        printf("The list is empty.\n");
        return;
    }
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d(next  = %d)",a[i].info,a[i].next);
        i--;
    }
    printf("\n");
}

void swap(int *a,int* b){       //swapping function.
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_list(struct List *l){          //function for sorting the list.
    int i=0,j;
    while(i < l->size){
        j = i+1;
        while(j <= l->size){
            if(l->array[j].info > l->array[i].info && j > i){
                swap(&l->array[i].info,&l->array[j].info);
            }
            j++;
        }
        i++;
    }
    i = l->size;
    while(i > 0){               //modifying the next value.
        l->array[i].next = l->array[i-1].info;
        i--;
    }
    l->array[i].next = -1;
}

int main(){
    struct List *list = create_list(12);
    insert(list,9);
    insert(list,34);
    insert(list,5);
    insert(list,1);
    insert(list,4);
    insert(list,25);
    insert(list,10);
    printf("The linked list is:\n\t");
    print_list(list);

    sort_list(list);
    printf("\nThe sorted list of original list is:\n\t");
    print_list(list);
    return 0;
}

