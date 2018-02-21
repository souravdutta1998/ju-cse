#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head!= NULL)
        head->prev = newnode;
    head = newnode;
}
void print_same_order(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void print_reverse_order(){
    struct node *temp=head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->prev;
    }
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
    print_reverse_order();
    return 0;
}
