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

void left_shrink(struct List *l,int start){      //from the key at index start to leftmost we shrink the list content.
    int i = start;
    while(i < l->size){
        l->array[i].info = l->array[i+1].info;
        l->array[i].next = l->array[i+1].next;
        i++;
    }

}

void delete_begin(struct List *l){      //function for delete a key from beginning.
    l->size--;
    print_list(l);
}

void delete_end(struct List *l){        //function for deleting a key from end.
    left_shift(l,0);
    l->size--;
    print_list(l);
}

void delete_nth(struct List *l,int index){      //function for deleting a key stored at 'index' index.
    int sie = (l->size+1) - index;      /*l->size+1 is the current size(count from end @0) of list
                                            and index is position from start @index 1*/
    left_shift(l,size);
    l->size--;
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

    int choice,num,index;
    printf("\nPress 0 for stop deletion.\n");
    printf("Press 1 for delete at beginning.\n");
    printf("Press 2 for delete at nth node.\n");
    printf("Press 3 for delete at end position.");
    do{
        printf("\nEnter deletion choice number:: ");
        scanf("%d",&choice);
        if(choice == 1)
            delete_begin(list);
        else if(choice == 3)
            delete_end(list);
        else if(choice == 2){
            printf("Specify the node position to delete by giving index number:\n");
            scanf("%d",&index);
            delete_nth(list,index);
        }
        else
            break;
    }
    while(choice != 0);

    return 0;
}
