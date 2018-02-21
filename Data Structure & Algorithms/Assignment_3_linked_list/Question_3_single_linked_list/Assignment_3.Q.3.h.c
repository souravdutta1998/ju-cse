#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head1;
void Insert(struct node** head11, int b){  //insert the new value to head.
    struct node* num = (struct node*)malloc(sizeof(struct node));
    num->data = b;
    num->next = NULL;
    if(*head11 == NULL){
        *head11 = num;
    }
    else{
        struct node *start;
        start = *head11;
        while(start->next != NULL){
            start = start->next;
        }
        start->next = num;
    }
}
void print_list(struct node *head){
    struct node* temp = head;
    while(temp != NULL){
        printf("-> %d ",temp->data); //Print the linked list.
        temp = temp->next;
    }
    printf("\n");
}
struct node* merge(struct node* m1, struct node* m2){
    struct node *head1 = NULL;
    while(m1 != NULL && m2 != NULL){
        if(m1->data < m2->data){
            Insert(&head1,m1->data);
            m1 = m1->next;
        }
        else if(m1->data >= m2->data){
            Insert(&head1,m2->data);
            m2 = m2->next;
        }
    }
    if(m1 != NULL)
        Insert(&head1,m1->data);

    if(m2 != NULL)
        Insert(&head1,m2->data);

    return head1;
}
int main(){
    struct node *head = NULL;
    struct node *head0 = NULL;
    Insert(&head,2);
    Insert(&head,16);
    Insert(&head,21);
    Insert(&head,31); //created a ordered linked list head = {1,2,6,9}
    Insert(&head0,3);
    Insert(&head0,28);
    Insert(&head0,40); //create another ordered linked list ={7,8,11}
    printf("Our @1st sorted List is::\n\t");
    print_list(head);
    printf("Our @2nd sorted List is::\n\t");
    print_list(head0);
    printf("The new list after merging are:\n\t");
    head1 = merge(head,head0); // returned head node from the function.
    while(head1 != NULL){
        printf("-> %d ",head1->data);
        head1 = head1->next;
    }

    return 0;
}
