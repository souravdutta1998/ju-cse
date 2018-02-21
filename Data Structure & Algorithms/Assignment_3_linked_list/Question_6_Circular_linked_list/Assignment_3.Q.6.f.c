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

void print_list(){
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
}

void delete_begin(){
    if(head == NULL)
        printf("Your linked list is empty\n");
    else{
        struct node *next,*tamp,*temp = head;
        tamp = head;
        while(tamp->next != head)
            tamp = tamp->next;
        free(temp);
        tamp->next = next;
        head = next;

    }
    printf("Our list after deletion at beginning::\n\t");
    print_list();
}
void delete_nth(int pos){
    int count = 1;
    struct node *prev,*nextt,*temp = head;
    while(count < pos){
        count++;
        prev = temp;
        temp = temp->next;
        if(prev->next == head)
            break;
    }

    if(count < pos){
        printf("The position you gave is not valid.\n");
        return;
    }
    nextt = temp->next;
    if(pos != 1)
        prev->next = nextt;
    else{
        struct node *tamp = head;
        while(tamp->next != head)
            tamp = tamp->next;
        tamp->next = nextt;
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
        struct node *prev = NULL,*start = head;
        while(start->next != head){
            prev = start;
            start = start->next;
        }
        prev->next = head;
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
