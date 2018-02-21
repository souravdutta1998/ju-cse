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
    if(head == NULL){
        newnode->previous = newnode;
        newnode->next = newnode;
    }
    else{
        /*Making a new pair of link near head node.*/
        newnode->next = head;
        head->previous = newnode;

        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;

        /*Making a pair of link at last node.*/
        temp->next = newnode;
        newnode->previous = temp;
    }
    head = newnode;
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

void delete_begin(){
    if(head == NULL)
        printf("Your linked list is empty\n");
    else{
        struct node *next,*tamp,*temp = head;
        tamp = head->previous;
        /*Making circular list from just after head node.*/
        tamp->next = head->next;
        (head->next)->previous = tamp;
        /*Assign head node to just next node of head.*/
        head = temp->next;
        /*delete the previous head node .*/
        free(temp);
    }
    printf("Our list after deletion at beginning::\n\t");
    print_list();
}
void delete_nth(int pos){
    int count = 1;
    struct node *prev,*nextt,*tamp,*temp = head;
    /*Finding the node at nth position and named it temp node.*/
    while(count < pos){
        count++;
        temp = temp->next;
        if(temp == head->previous)
            break;
    }

    if(count < pos){
        printf("The position you gave is not valid.\n");
        return;
    }
    prev = temp->previous;
    nextt = temp->next;

    prev->next = nextt;
    nextt->previous = prev;

    if(pos == 1){
        head = nextt;
    }
    free(temp);
    printf("Our list after deletion at position %d::\n\t",pos);
    print_list();
}
void delete_end(){
    if(head == NULL)
        printf("Your linked list is empty\n");
    else{
        struct node *prev,*start;
        start = head->previous;
        prev = start->previous;
        prev->next = head;
        head->previous = prev;
        free(start);
    }
    printf("Our list after deletion at the end::\n\t");
    print_list();
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);        /*Ordered Increasing insertion */
    insert(200);
    insert(77);
    insert(44);
    insert(12);
    insert(6);
    printf("Our original list ::\n\t");
    print_list();
    int choice,num,index;
    printf("\nPress 0 for stop deletion.\n");
    printf("Press 1 for delete at beginning.\n");
    printf("Press 2 for delete at nth node.\n");
    printf("Press 3 for delete at end position.");
    do{
        printf("\nEnter deletion choice number:: ");
        scanf("%d",&choice);
        if(choice == 1)
            delete_begin();
        else if(choice == 3)
            delete_end();
        else if(choice == 2){
            printf("Specify the node position to delete by giving index number:\n");
            scanf("%d",&index);
            delete_nth(index);
        }
        else
            break;
    }
    while(choice != 0);
    return 0;
}
