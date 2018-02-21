#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head;

void insert(int data){        //function for inserting data at the beginning.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->previous = NULL;
    newnode->next = head;
    if(head!=NULL)
        head->previous = newnode;
    head = newnode;
}
void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void move_last2_first(){
    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    printf("\n Now,Your Linked list is like this::(here we move the last element %d to first element %d) \n\t",temp->data,head->data);
    int swap;
    swap = head->data;
    head->data = temp->data;
    temp->data = swap;
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Linked list is like this:: \n\t");
    print_list();
    move_last2_first();
    print_list();
}
