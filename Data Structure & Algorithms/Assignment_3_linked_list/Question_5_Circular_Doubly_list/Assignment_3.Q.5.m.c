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

void print_list(){
    if(head == NULL){
        printf("Your list is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d...",(temp->next)->data);
}

int find_length(){                             //function to return length of a list.
    int count = 0;
    struct node *temp = head;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    return count+1;
}

void delete_alter_list(int n){
    int count = 0;
    struct node *next;
    while(count < n){
        next = head->next;
        printf("Deleted element = %d\n",head->data);
        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = next;
        next->previous = temp;

        free(head);
        if(next != head)
            head = next;
        else
            head = NULL;
        count++;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Circular Linked list is like this:: \n\t");
    print_list();
    int n;
    do{
        printf("\nHow many elements you want to delete one at a time:: ");
        scanf("%d",&n);
        if(n > find_length())
            printf("You are giving input wrong as only %d elements are left\n",find_length());
        else
            delete_alter_list(n);
        if(head == NULL)
            break;
    }
    while(1);
    return 0;
}
