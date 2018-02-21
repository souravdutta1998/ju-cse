#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
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

void delete_list(){         //function for deleting whole list.
    struct node *prev = NULL,*cur = head,*next;
    while(cur != NULL){
        next = cur->next;
        prev = cur;
        printf("\nDeleted element = %d",cur->data);
        free(cur);
        cur = next;
    }
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
    delete_list();
    return 0;
}
