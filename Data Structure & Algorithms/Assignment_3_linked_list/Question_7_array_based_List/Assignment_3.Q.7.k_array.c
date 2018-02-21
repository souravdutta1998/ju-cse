#include<stdio.h>
#include<stdlib.h>

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
    int i=0;
    struct node *a = l->array;
    while(i <= l->size){
        printf("->%d",a[i].info);
        i++;
    }
}

void swap(int *a,int *b){       //swapping function between two number.
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_list(struct List *l){     //function for pairwise swapping.
    int a=0,b =a+1;
    while(a <= l->size && b <= l->size){
        swap(&l->array[a].info,&l->array[b].info);
        l->array[b].next = l->array[a].info;
        if(a != 0)
            l->array[a].next = l->array[b-2].info;
        a = b+1;
        b = a+1;
    }
}

int main(){
    struct List *list = create_list(10);
    insert(list,34);
    insert(list,5);
    insert(list,1);
    insert(list,4);
    insert(list,25);
    insert(list,10);
    printf("The linked list is:\n\t");
    print_list(list);

    swap_list(list);
    printf("\nYour List after swapping pairwise elements is::\n\t");
    print_list(list);
    return 0;
}
