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
    if(head == NULL)
        newnode->next = newnode;
    else{
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
    printf("  Circular head = %d...",temp->data);
}
void reverse_list(){
    struct node *cur=head,*prev=NULL,*next=NULL;
    while(next != head){
        next = cur->next;
        if(prev == NULL){
            struct node *temp=cur;
            while(temp->next != head)
                temp = temp->next;
            cur->next = temp;
        }
        else
            cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(12);
    insert(56);        /*Ordered Increasing insertion */
    insert(200);
    insert(77);
    insert(6);
    printf("The Original list is:\n\t");
    print_list();
    reverse_list();
    printf("\nThe list after reversing the original list is:\n\t");
    print_list();
    return 0;
}
