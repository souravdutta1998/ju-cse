#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = head;
    head = newnode;
}
void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void delete_begin(){
    if(head == NULL)
        printf("Your linked list is empty\n");
    else{
        struct node *next,*temp = head;
        next = temp->next;
        free(temp);
        head = next;
    }
    printf("Our list after deletion at beginning::\n\t");
    print_list();
}
void delete_nth(int pos){
    int count = 1;
    struct node *prev,*next,*temp = head;
    while(count < pos){
        count++;
        prev = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        next = temp->next;
        if(pos != 1)
            prev->next = next;
        else
            head = next;
        free(temp);
        printf("Our list after deletion at position %d::\n\t",pos);
        print_list();
    }
    else
        printf("The index you gave is not valid.\n");
}
void delete_end(){
    if(head == NULL)
        printf("Your linked list is empty\n");
    else{
        struct node *prev = NULL,*start = head;
        while(start->next != NULL){
            prev = start;
            start = start->next;
        }
        prev->next = NULL;
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
