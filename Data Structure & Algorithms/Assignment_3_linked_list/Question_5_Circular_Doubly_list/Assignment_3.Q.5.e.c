#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};
struct node* head;
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

void insert_list(int data,struct node **headd){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(*headd == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
    }
    else{
        newnode->next = *headd;
        (*headd)->previous = newnode;
        struct node *temp=(*headd);
        while(temp->next != *headd)
            temp = temp->next;
        temp->next = newnode;
        newnode->previous = temp;
    }
    *headd = newnode;
}

void print_list(){
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d....",(temp->next)->data);
}

void append_headd_inHead(struct node *headd){
    struct node *tail1,*tail2;
    tail1 = head->previous;
    tail2 = headd->previous;

    tail1->next = headd;
    headd->previous = tail1;

    tail2->next = head;
    head->previous = tail2;
    print_list();
}

int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Our original Doubly Circular list is::\n\t");
    print_list();

    struct node *temp,*headd = NULL;
    insert_list(5,&headd);
    insert_list(17,&headd);
    insert_list(4,&headd);
    insert_list(10,&headd);
    insert_list(6,&headd);
    printf("\nINSERTED Circular Doubly lIST IS:: \n\t");
    temp = headd;
    while(temp->next != headd){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d....",(temp->next)->data);

    printf("\nAfter appending the 2nd list in first List, The new Extended 1st Circular Doubly List is::\n\t");
    append_headd_inHead(headd);

    return 0;
}
