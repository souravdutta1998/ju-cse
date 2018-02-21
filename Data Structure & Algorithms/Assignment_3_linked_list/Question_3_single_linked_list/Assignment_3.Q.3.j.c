#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insert(int data){                   //function for inserting data at the beginning.
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
void remove_duplicate(){        //function for removing the duplicates.
    int num;
    struct node *prev,*next,*temp2,*cur,*temp1 = head;
    while(temp1 != NULL){
        num = temp1->data;
        prev = NULL;
        temp2 = head;

        while(temp2 != NULL){
            next = temp2->next;
            /*condition for one node to be copy of another.*/
            if(temp2->data == temp1->data && temp1->next != temp2->next){
                prev->next = next;
                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            prev = temp2;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(1);
    insert(2);
    insert(3);
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    printf("Your Original Linked list is like this:: \n\t");
    print_list();
    remove_duplicate();
    printf("\nThe list after removing of all copies of all element if present is:\n\t");
    print_list();
    return 0;
}
