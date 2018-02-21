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
    newnode->previous = NULL;
    newnode->next = head;
    if(head!=NULL)
        head->previous = newnode;
    head = newnode;
}
void print_list(){
    struct node *temp = head;
    while(temp->next != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d\n\t(reverse/order)",temp->data);
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->previous;
    }
}
void reverse_list(){
    struct node *cur=head,*head1,*prev=NULL,*nextt;
    while(cur != NULL){
        nextt = cur->next;
        cur->previous = nextt;
        cur->next = prev;
        prev = cur;
        cur = nextt;
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
