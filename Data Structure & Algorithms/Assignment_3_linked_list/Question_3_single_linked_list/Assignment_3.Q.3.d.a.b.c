#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = head;
    head = newnode;
}
void print_same_order(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void print_reverse_order(struct node *temp){
    if(temp == NULL)
        return;
    else
        print_reverse_order(temp->next);
    printf("->%d",temp->data);
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Printing the list in same order they inserted:\n\t");
    print_same_order();
    printf("\nPrinting the list in same order they inserted:\n\t");
    print_reverse_order(head);
    return 0;
}
