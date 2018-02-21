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
    printf(" Circular head = %d\n\t(reverse/order)",(temp->next)->data);
    while(temp != head){
        printf("->%d",temp->data);
        temp = temp->previous;
    }
    printf("->%d",temp->data);
    printf(" Circular head = %d",(temp->previous)->data);
}

int find_length(){
    int count = 0;
    struct node *temp = head;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    return count+1;
}
int main(){
    int l;
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Circular Doubly Linked list is like this:: \n\t");
    print_list();
    l = find_length();
    printf("\nSize of list is %d\n",l);
    return 0;
}
