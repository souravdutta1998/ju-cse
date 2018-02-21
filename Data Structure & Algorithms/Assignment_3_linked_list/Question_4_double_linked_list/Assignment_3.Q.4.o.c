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

void delete_list(){
    struct node *cur = head,*nextt;
    while(cur != NULL){
        nextt = cur->next;
        if(nextt!=NULL)
            nextt->previous = NULL;
        printf("\nDeleted element = %d",cur->data);
        free(cur);
        cur = nextt;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Doubly Linked list is like this:: \n\t");
    print_list();
    delete_list();
    return 0;
}
