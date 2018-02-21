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
            if(a[size].info > a[size-1].info){
                flag = 0;
                break;
            }
            size--;
        }
    }

    else if(a[size].info > a[size-1].info){         //for decreasing order.
        size--;
        flag = 2;
        while(size > 0){
            if(a[size].info < a[size-1].info){
                flag = 0;
                break;
            }
            size--;
        }
    }
    return flag;
}

void print_list(struct List *l){        //function to print the list in revere order.
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d",a[i].info);
        i--;
    }
}

void insert_begin(struct List *l,int data){           //function for inserting key at beginning.
    l->array[l->size+1].info = data;
    if(l->size == -1)
       l->array[l->size+1].next = -1;
    else
        l->array[l->size+1].next = l->array[l->size].info;     /*storing the next info of
                                                            previous info in next field of current List array.*/
    l->size++;              //incrementing the list size by 1.
    print_list(l);
}

void Expand(struct List *l,int last){       //function for increasing elements index by 1 left up-to element of index last.
    int i,size = l->size+1;
    for(i=size;i> last;i--){
        l->array[i].info = l->array[i-1].info;
        if(i != last+1)
            l->array[i].next = l->array[i-1].next;
    }
}
void insert_nth(struct List *l,int data,int index){ //function for inserting a key at nth position from leftmost.
    if(index > l->size+1){
        printf("The elements at index you gave does n't exit:\n");
        return;
    }
    if(l->size != -1){
        index = l->size - index + 2;
        Expand(l,index);
        l->array[index+1].next = data;
    }
    l->array[index].info = data;
    if(index != 0)
        l->array[index].next = l->array[index-1].info;
    else
        l->array[index].next = -1;
    l->size++;
    print_list(l);
}

void insert_nth_order(struct List *l,int data,int order){
    int i=l->size;
    if(order == 1){         //if the list is in increasing order.
        if(l->size != -1){
            while(l->array[i].next <= data)
                i--;
            Expand(l,i);
            l->array[i+1].next = data;
        }
    }

    if(order == 2){         //else if it is in decreasing order.
        if(l->size != -1){
            while(l->array[i].next >= data)
                i--;
            Expand(l,i);
            l->array[i+1].next = data;
        }
    }
    l->array[i].info = data;
    l->array[i].next = l->array[i-1].info;
    l->size++;
    print_list(l);
}

void insert_end(struct List *l,int data){       //function for inserting a key at rightmost position.
    if(l->size != -1){
        Expand(l,0);
        l->array[1].next = data;
    }
    l->array[0].info = data;
    l->array[0].next = -1;
    l->size++;
    print_list(l);
}

int main(){
    struct List *list = create_list(12);
    int choice,num,index;
    printf("\nPress 0 for stop insertion.\n");
    printf("Press 1 for insert at beginning.\n");
    printf("Press 2 for insert at nth node.\n");
    printf("Press 3 for insert at end position.\n");
    do{
        printf("\nEnter your data to be insert with insertion choice number:: ");
        scanf("%d %d",&num,&choice);
        if(choice == 1)
            insert_begin(list,num);
        else if(choice == 3)
            insert_end(list,num);
        else if(choice == 2){
            if(check_orderness(list) == 0){
                printf("Specify the node before you want to insert by giving index number:\n");
                scanf("%d",&index);
                insert_nth(list,num,index);
            }
            else
                insert_nth_order(list,num,check_orderness(list));
        }
        else
            break;
    }
    while(choice != 0);
    return 0;
}
