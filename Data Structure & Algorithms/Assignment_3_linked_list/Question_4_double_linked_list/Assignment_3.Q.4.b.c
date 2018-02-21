#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;
}

void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}

int find_length(){
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int main(){
    int l;
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Doubly Linked list is like this:: \n\t");
    print_list();
    l = find_length();
    printf("\nSize of list is %d\n",l);
    return 0;
}
