#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    if(head == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
    }
    else{
        newnode->next = head;
        head->previous = newnode;
        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->previous = temp;
    }
    head = newnode;
}
void print_same_order(){
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d....",(temp->next)->data);
}
void print_reverse_order(){
    struct node *temp = head->previous;
    while(temp != head){
        printf("->%d",temp->data);
        temp = temp->previous;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d....",(temp->previous)->data);
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
