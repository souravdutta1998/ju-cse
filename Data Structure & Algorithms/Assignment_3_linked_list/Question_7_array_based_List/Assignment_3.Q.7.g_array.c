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

int check_orderness(struct List *l){        //function for comparison.
    if(l->size == -1){
        return 0;
    }
    int i,size,flag;
    struct node *a = l->array;

    for(i = l->size ; i > 0 ; i--){
        if(a[i].info != a[i-1].info){           //choosing the index of distinct key in the list.
            size = i;
            break;
        }
    }

    if(a[size].info < a[size-1].info){          //for increasing order.
        size--;
        flag = 1;
        while(size > 0){
            if(a[size].info > a[size-1].info)
                flag = 0;
            size--;
        }
    }

    else if(a[size].info > a[size-1].info){         //for decreasing order.
        size--;
        flag = 2;
        while(size > 0){
            if(a[size].info < a[size-1].info)
                flag = 0;
            size--;
        }
    }

    if(flag == 1)
        printf("\nThe linked list is in Increasing ordered");
    else if(flag == 2)
        printf("\nThe linked list is in Decreasing ordered");
    else
        printf("\nThe linked list is not in ordered");
}

int main(){
    struct List *list = create_list(12);
    insert(list,18);
    insert(list,14);
    insert(list,14);
    insert(list,20);
    insert(list,25);
    insert(list,25);
    printf("The linked list is:\n\t");
    print_list(list);
    check_orderness(list);
    return 0;
}
