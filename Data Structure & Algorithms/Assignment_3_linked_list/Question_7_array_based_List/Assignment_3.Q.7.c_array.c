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

void equality_check(struct List *l1,struct List *l2){
    if(l1->size != l1->size){
        printf("\nThe list1 and list2 are not equal as size of lists are not equal.\n");
        return;
    }

    struct node *a1 = l1->array;
    struct node *a2 = l2->array;
    int size = l1->size;

    while(size >= 0){
        if(a1[size].info != a2[size].info){
            printf("\nThe list1 and list2 are equal in size but contents are not same.\n");
            return;
        }
        size--;
    }
    printf("\nThe sizes of list1 and list2 are equal as well as size of lists are also equal.\n");
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
    insert(list2,4);
    insert(list2,5);
    insert(list2,1);
    insert(list2,4);
    insert(list2,25);
    insert(list2,10);
    printf("\nThe Second linked list is:\n\t");
    print_list(list2);
    equality_check(list1,list2);

    return 0;
}
