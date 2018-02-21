#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Insert(struct node** head11, int b){  //insert the new value to head.
    struct node* num = (struct node*)malloc(sizeof(struct node));
    num->data = b;
    if(*head11 == NULL){
        num->next = num;
        *head11 = num;
    }
    else{
        struct node *start;
        start = *head11;
        while(start->next != *head11){
            start = start->next;
        }
        start->next = num;
        num->next = *head11;
    }
}
void print_list(struct node *head){
    struct node* temp = head;
    while(temp->next != head){
        printf("->%d",temp->data); //Print the linked list.
        temp = temp->next;
    }
    printf("->%d\n",temp->data);
}

void merge(struct node *head3, struct node *head4){
    struct node *head1 = NULL;
    struct node *m1,*m2;
    m1 = head3;
    m2 = head4;
    while(m1->next != head3 && m2->next != head4){
        if(m1->data < m2->data){
            Insert(&head1,m1->data);
            m1 = m1->next;
        }
        else if(m1->data >= m2->data){
            Insert(&head1,m2->data);
            m2 = m2->next;
        }
    }
    if(m1->next == head3 || m2->next == head4){
        if(m1->data < m2->data){
            Insert(&head1,m1->data);
            m1 = m1->next;
        }
        else if(m1->data >= m2->data){
            Insert(&head1,m2->data);
            m2 = m2->next;
        }
    }
    while(m1->next != head3->next){
        Insert(&head1,m1->data);
        m1 = m1->next;
    }
    while(m2->next != head4->next){
        Insert(&head1,m2->data);
        m2 = m2->next;
    }
    print_list(head1);
}

int main(){
    struct node *head = NULL;
    struct node *head0 = NULL;
    struct node *head1;
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
    merge(head,head0); // function for merging two sorted list.

    return 0;
}
