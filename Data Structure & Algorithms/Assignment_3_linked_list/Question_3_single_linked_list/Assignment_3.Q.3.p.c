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
void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void reverse_list(){
    struct node *cur=head,*prev=NULL,*next;
    while(cur != NULL){
        next = cur->next;
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
