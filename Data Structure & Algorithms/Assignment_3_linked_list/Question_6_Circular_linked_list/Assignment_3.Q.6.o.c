#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL)
        newnode->next = newnode;
    else{
        newnode->next = head;
        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
    head = newnode;
}

void print_list(){
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    temp = temp->next;
    printf(" Circular head = %d...",temp->data);
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
    printf("Your Original Circular Linked list is like this:: \n\t");
    print_list();
    delete_list();
    return 0;
}
