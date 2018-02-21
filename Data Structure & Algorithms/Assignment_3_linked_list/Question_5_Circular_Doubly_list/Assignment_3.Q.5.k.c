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
    struct node *temp = head;
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d...",(temp->next)->data);
}

void swap(){              //function for pairwise elements swapping of a list.
    int c;
    struct node *prev=head,*cur;
    cur = head->next;
    while(cur != head){
        c = prev->data;
        prev->data = cur->data;
        cur->data= c;
        prev = cur->next;
        if(prev->next != head)
            cur = prev->next;
        else
            break;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Circular List is::\n\t");
    print_list();
    swap();
    printf("\nYour List after swapping pairwise elements is::\n\t");
    print_list();
    return 0;
}
