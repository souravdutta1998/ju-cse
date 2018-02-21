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
    newnode->data = data;
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

void print_list(){
    if(head == NULL){
        printf("Your list is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d...",(temp->next)->data);
}

void delete_list(){
    struct node *prev = NULL,*cur = head,*next;
    while(cur != NULL){
        next = cur->next;
        prev = cur;
        printf("\nDeleted element = %d",cur->data);
        free(cur);
        if(next != head)
            cur = next;
        else
            cur = NULL;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Circular Doubly Linked list is like this:: \n\t");
    print_list();
    delete_list();
    return 0;
}
