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

struct node search_key(struct List *l,int data){        //function for searching the key in the list.
    int i=l->size;
    struct node *a = l->array;
    while(a[i].info != data && i>=0 ){
        i--;
    }
    return a[i];
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
        if(a[i].info == target.info){
            a[i].next = a[i-1].next;
            left_shrink(l,i);
            l->size--;
            break;
        }
        i--;
    }

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
    struct node key = search_key(list,4);
    printf("\nKey->data = %d\n",key.info);
    delete_key(list,key);
    printf("Now,The linked list is:\n\t");
    print_list(list);
    return 0;
}
