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
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d",a[i].info);
        i--;
    }
}

struct List* append_list_Head_tail(struct List *l1,struct List *l2){      //function for appending two list tail to head.
    int i=0;
    while(i <= l1->size){
        l2->array[l2->size+1].info = l1->array[i].info;
        l2->array[l2->size+1].next = l2->array[l2->size].info;
        l2->size++;
        i++;
    }
    return l2;
}
int main(){
    struct List *list1 = create_list(12);
    insert(list1,34);
    insert(list1,5);
    insert(list1,1);
    insert(list1,4);
    insert(list1,25);
    insert(list1,10);
    printf("The First linked list is:\n\t");
    print_list(list1);

    struct List *list2 = create_list(12);
    insert(list2,41);
    insert(list2,5);
    insert(list2,10);
    insert(list2,3);
    insert(list2,5);
    insert(list2,1);
    printf("\nINSERTED lIST IS:: \n\t");
    print_list(list2);
    list2 = append_list_Head_tail(list1,list2);
    printf("\nAfter appending the 1st list's tail in 2nd List's head, The new Extended 2nd List is::\n\t");
    print_list(list2);
    return 0;
}
