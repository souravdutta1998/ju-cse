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
    int i=0;
    struct node *a = l->array;
    while(i <= l->size){
        printf("->%d",a[i].info);
        i++;
    }
}

void delete_alter_list(struct List *l,int n){   //function for deleting n key at a time from a list.
    int count = 0;
    while(count < n){
        count++;
        printf("Deleted %d\n",l->array[l->size].info);
        l->size--;
    }
    print_list(l);
}

int main(){
    struct List *list = create_list(12);
    insert(list,34);
    insert(list,5);
    insert(list,1);
    insert(list,4);
    insert(list,25);
    insert(list,10);
    printf("The linked list is:\n\t");
    print_list(list);

    int n;
    do{
        printf("\nHow many elements you want to delete one at a time:: ");
        scanf("%d",&n);
        if(n <= list->size+1)
            delete_alter_list(list,n);
        else
            printf("You are giving input wrong as only %d elements are left\n",list->size+1);
        if(list->size == -1)
            break;
    }
    while(1);

    return 0;
}
