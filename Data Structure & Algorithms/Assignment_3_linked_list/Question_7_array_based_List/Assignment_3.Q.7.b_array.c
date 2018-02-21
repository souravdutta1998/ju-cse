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

void print_list(struct List *l){
    int i=l->size;
    struct node *a = l->array;
    while(i >= 0){
        printf("->%d",a[i].info);
        i--;
    }

}

int find_length(struct List *l){
    return l->size+1;
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
    printf("\nThe length of your list is %d\n",find_length(list));

    return 0;
}
