#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    int next;
};
struct List{
    int size;
    struct node *array;
};

struct List *create_list(int V){
    struct List *newlist = (struct List*)malloc(sizeof(struct List));
    newlist->size = -1;
    newlist->array = (struct node*)malloc(V*sizeof(struct node));
    return newlist;
}

void insert(struct List *l,int data){
    l->array[l->size+1].info = data;
    l->array[l->size+1].next = l->array[l->size].info;
    l->size++;
}
void print_same_order(struct List *l){
    int i=0;
    struct node *a = l->array;
    while(i <= l->size){
        printf("->%d",a[i].info);
        i++;
    }
    printf("\n");
}

void print_reverse_order(struct List *l){
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d",a[i].info);
        i--;
    }
    printf("\n");
}

int main(){
    struct List *list = create_list(12);
    insert(list,34);
    insert(list,5);
    insert(list,1);
    insert(list,4);
    insert(list,25);
    insert(list,10);
    printf("The linked list in ordered is:\n\t");
    print_reverse_order(list);

    printf("The linked list in reverse order is:\n\t");
    print_same_order(list);

    return 0;
}
