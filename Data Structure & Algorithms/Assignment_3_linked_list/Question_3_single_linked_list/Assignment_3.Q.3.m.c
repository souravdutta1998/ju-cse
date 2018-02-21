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

int find_length(){                             //function to return length of a list.
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_alter_list(int n){      //function for deleting n key at a time from a list.
    int count = 0;
    struct node *next;
    while(count < n){
        next = head->next;
        printf("Deleted element = %d\n",head->data);
        free(head);
        head = next;
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
    printf("Your Original Linked list is like this:: \n\t");
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
