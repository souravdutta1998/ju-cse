#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node* next;
};
struct node* head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;
}
void insert_list(int data,struct node **headd){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = *headd;
    struct node *h;
    h = *headd;
    if(h != NULL)
        h->prev = newnode;
    *headd = newnode;
}
void append_headd_inHead(struct node *headd){
    struct node *move = head;
    while(move->next != NULL){
        move = move->next;
    }
    move->next = headd;
    headd->prev = move;
    struct node *temp = head;
    while(temp->next != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf("\nIn opposite move ");
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->prev;
    }
}
void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Our original list is::\n\t");
    print_list();

    struct node *temp,*headd = NULL;
    insert_list(5,&headd);
    insert_list(17,&headd);
    insert_list(4,&headd);
    insert_list(10,&headd);
    insert_list(6,&headd);
    printf("\nINSERTED lIST IS:: \n\t");
    temp = headd;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }

    printf("\nAfter appending the 2nd list in first List, The new Extended 1st List is::\n\t");
    append_headd_inHead(headd);

    return 0;
}
