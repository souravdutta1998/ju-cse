#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

void Insert_end(struct node **head,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    if(*head == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
        *head = newnode;
    }
    else{
        struct node *temp=(*head);
        while(temp->next != *head)
            temp = temp->next;
        temp->next = newnode;
        newnode->previous = temp;

        newnode->next = *head;
        (*head)->previous = newnode;
    }
}

void print_list(struct node *head){
    struct node* temp = head;
    while(temp->next != head){
        printf("->%d",temp->data); //Print the linked list.
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d....\n",(temp->next)->data);
}

void merge(struct node *head3, struct node *head4){
    struct node *head1 = NULL;
    struct node *m1,*m2;
    m1 = head3;
    m2 = head4;
    while(m1->next != head3 && m2->next != head4){
        if(m1->data < m2->data){
            Insert_end(&head1,m1->data);
            m1 = m1->next;
        }
        else if(m1->data >= m2->data){
            Insert_end(&head1,m2->data);
            m2 = m2->next;
        }
    }
    if(m1->next == head3 || m2->next == head4){
        if(m1->data < m2->data){
            Insert_end(&head1,m1->data);
            m1 = m1->next;
        }
        else if(m1->data >= m2->data){
            Insert_end(&head1,m2->data);
            m2 = m2->next;
        }
    }
    while(m1->next != head3->next){
        Insert_end(&head1,m1->data);
        m1 = m1->next;
    }
    while(m2->next != head4->next){
        Insert_end(&head1,m2->data);
        m2 = m2->next;
    }
    print_list(head1);
}

int main(){
    struct node *head = NULL;
    struct node *head0 = NULL;
    struct node *head1;
    Insert_end(&head,2);
    Insert_end(&head,16);
    Insert_end(&head,21);
    Insert_end(&head,31); //created a ordered linked list head = {1,2,6,9}
    Insert_end(&head0,3);
    Insert_end(&head0,28);
    Insert_end(&head0,40); //create another ordered linked list ={7,8,11}
    printf("Our @1st sorted List is::\n\t");
    print_list(head);
    printf("Our @2nd sorted List is::\n\t");
    print_list(head0);
    printf("The new list after merging are:\n\t");
    merge(head,head0); // function for merging two sorted list.

    return 0;
}
