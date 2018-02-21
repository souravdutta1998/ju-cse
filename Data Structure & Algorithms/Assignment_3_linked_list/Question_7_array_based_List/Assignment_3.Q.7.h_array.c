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

void print_list(struct List *l){        //function to print the list in revere order.
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d",a[i].info);
        i--;
    }
}

void print_same_order(struct List *l){          //function to print the list in same order they inserted.
    int i=0;
    struct node *a = l->array;
    while(i <= l->size){
        printf("->%d ",a[i].info);
        i++;
    }
    printf("\n");
}

struct List* merge_list1_list2(struct List *l1,struct List *l2){        //function for merging two sorted list.
    struct List *l = create_list(l1->size+l2->size+2);
    int i1,i2,i=0;
    i1 = l1->size;
    i2 = l2->size;
    while(i1 >= 0 && i2 >= 0){
        if(l1->array[i1].info <= l2->array[i2].info){
            insert(l,l1->array[i1].info);
            i1--;
        }
        else{
            insert(l,l2->array[i2].info);
            i2--;
        }
    }
    while(i1 >= 0){
            insert(l,l1->array[i1].info);
            i1--;
    }
    while(i2 >= 0){
            insert(l,l2->array[i2].info);
            i2--;
    }
    return l;
}
int main(){
    struct List *list1 = create_list(10);
    insert(list1,34);
    insert(list1,25);
    insert(list1,16);
    insert(list1,9);
    insert(list1,5);
    insert(list1,1);
    printf("The First linked list is:\n\t");
    print_list(list1);

    struct List *list2 = create_list(10);
    insert(list2,44);
    insert(list2,28);
    insert(list2,22);
    insert(list2,19);
    insert(list2,7);
    insert(list2,2);
    printf("The First linked list is:\n\t");
    print_list(list2);

    struct List *list3 = merge_list1_list2(list1,list2);
    printf("\nAfter merging the 1st list and 2nd List, The new Merged List is::\n\t");
    print_same_order(list3);
    return 0;
}
