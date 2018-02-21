#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head;

void insert(int data){                   //function for inserting data at the beginning.
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
    printf("\tCirculation head = %d->....\n\t(reverse/order)",(temp->next)->data);
    while(temp != head){
        printf("->%d",temp->data);
        temp = temp->previous;
    }
    printf("->%d",temp->data);
}
void remove_duplicate(){
    int num;
    struct node *prev,*next,*temp2,*cur,*temp1 = head;
    while(temp1->next != head){
        num = temp1->data;
        prev = NULL;
        temp2 = head;
        while(temp2->next != head){
            next = temp2->next;

            /*condition for one node to be copy of another.*/

            if(temp2->data == temp1->data && temp1->next != temp2->next){
                prev->next = next;
                next->previous = prev;

                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            prev = temp2;
            temp2 = temp2->next;
        }
        if(temp2->next == head){
            next = temp2->next;
            if(temp2->data == temp1->data && temp1->next != temp2->next){
                prev->next = next;
                next->previous = prev;

                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            prev = temp2;
        }
        temp1 = temp1->next;
    }
    if(temp1->next == head){
        num = temp1->data;
        prev = NULL;
        temp2 = head;
        while(temp2->next != head){
            next = temp2->next;

            /*condition for one node to be copy of another.*/

            if(temp2->data == temp1->data && temp1->next != temp2->next){
                prev->next = next;
                next->previous = prev;

                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            prev = temp2;
            temp2 = temp2->next;
        }
        if(temp2->next == head){
            next = temp2->next;
            if(temp2->data == temp1->data && temp1->next != temp2->next){
                prev->next = next;
                next->previous = prev;

                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            prev = temp2;
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
    printf("Your Original Circular Doubly Linked list is like this:: \n\t");
    print_list();
    remove_duplicate();
    printf("\nThe list after removing of all copies of all element if present is:\n\t");
    print_list();
    return 0;
}
