#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;
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
    }
    head = newnode;
}
void insert_list(int data,struct node **headd){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(*headd == NULL)
        newnode->next = newnode;
    else{
        struct node *temp;
        newnode->next = (*headd);
        temp = *headd;
        while(temp->next != *headd)
            temp = temp->next;
        temp->next = newnode;
    }
    *headd = newnode;
}
void append_headd_inHead(struct node *headd){
    struct node *tamp,*move = head;
    while(move->next != head){
        move = move->next;
    }
    move->next = headd;
    tamp = headd;
    while(tamp->next != headd){
        tamp = tamp->next;
    }
    tamp->next = head;
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
}
void print_list(){
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Our original Circular list is::\n\t");
    print_list();

    struct node *temp,*headd = NULL;
    insert_list(5,&headd);
    insert_list(17,&headd);
    insert_list(4,&headd);
    insert_list(10,&headd);
    insert_list(6,&headd);
    printf("\nINSERTED Circular lIST IS:: \n\t");
    temp = headd;
    while(temp->next != headd){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);

    printf("\nAfter appending the 2nd list in first List, The new Extended 1st Circular List is::\n\t");
    append_headd_inHead(headd);

    return 0;
}
