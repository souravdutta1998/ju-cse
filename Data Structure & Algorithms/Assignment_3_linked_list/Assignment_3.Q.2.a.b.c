#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;
struct node* head0;
FILE *f1,*f2;
void Insert_reverseorder_read(int data){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    f2 = fopen("list2","w");
    newnode->data = data;
    newnode->next = head0;
    head0 = newnode;
    fclose(f2);
}
void Insert_inorder_read(int data){
    struct node *newnode,*start;
    newnode = (struct node*)malloc(sizeof(struct node));
    f1 = fopen("list1","w");
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else{
        start = head;
        while(start->next != NULL){
            start = start->next;
        }
        start->next = newnode;
    }
    fclose(f1);
}
int main(){
    head = NULL;
    head0 = NULL;
    Insert_inorder_read(6);
    Insert_reverseorder_read(6);
    Insert_inorder_read(12);
    Insert_reverseorder_read(12);
    Insert_inorder_read(9);
    Insert_reverseorder_read(9);
    Insert_inorder_read(16);
    Insert_reverseorder_read(16);
    Insert_inorder_read(1);
    Insert_reverseorder_read(1);
    printf("Linked list in order they are read are:\n\t");
    f1 = fopen("list1","r");
    struct node* temp = head;
    while(temp != NULL){
        fprintf(list1.txt,"->%d",temp->data);
        temp = temp->next;
    }
    fclose(f1);
    printf("\nLinked list in reverse order they are read are:\n\t");
    f2 = fopen("list2","w");
    struct node* tamp = head0;
    while(tamp != NULL){
        fprintf(list2.txt,"->%d",tamp->data);
        tamp = tamp->next;
    }
    fclose(f2);
    return 0;
}
