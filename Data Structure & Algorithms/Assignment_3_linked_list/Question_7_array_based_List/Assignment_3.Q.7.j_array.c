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
        printf("->%d(next=%d)",a[i].info,a[i].next);
        i--;
    }
    printf("\n");
}


void left_shrink(struct List *l,int start){      //from the key at index start to leftmost we shrink the list content.
    int i = start;
    while(i < l->size){
        l->array[i].info = l->array[i+1].info;
        l->array[i].next = l->array[i+1].next;
        i++;
    }

}

void delete_key(struct List *l,struct node target){     //function for deleting the node target.
    int i=l->size;
    struct node *a = l->array;
    while(i>=0 ){

        if(a[i].info == target.info && a[i].next == target.next){
            if(i != 0){
                a[i].info = a[i-1].next;
                a[i].next = a[i-1].next;
            }
            else
                a[i].next = -1;
            left_shrink(l,i);
            if(i > 0)
                l->array[i].next = l->array[i-1].info;
            else
                l->array[i].next = -1;
            l->size--;
            break;
        }
        i--;
    }

}

void remove_duplicate(struct List *l){      //function for removing the duplicates.
    int i1,i2,size;
    size = l->size;
    i1 = size;
    while(i1 >= 0){
        i2 = size;
        while(i2 >= 0){
            /*Checking the duplicate value.*/
            if(l->array[i1].info == l->array[i2].info && l->array[i1].next != l->array[i2].next){
                delete_key(l,l->array[i2]);
                print_list(l);
            }
            i2--;
        }
        i1--;
    }
}

int main(){
    struct List *list = create_list(12);
    insert(list,1);
    insert(list,2);
    insert(list,3);
    insert(list,1);
    insert(list,2);
    insert(list,3);
    insert(list,2);
    printf("The linked list is:\n\t");
    print_list(list);
    remove_duplicate(list);
    printf("\nNow,The linked list is:\n\t");
    print_list(list);
    return 0;
}
