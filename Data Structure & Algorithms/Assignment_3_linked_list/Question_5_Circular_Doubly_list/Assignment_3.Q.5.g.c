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
    newnode->data= data;
    if(head == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
    }
    else{
        /*Making a new pair of link near head node.*/
        newnode->next = head;
        head->previous = newnode;

        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;

        /*Making a pair of link at last node.*/
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
    printf(" Circular head = %d....",(temp->next)->data);
}

void check_orderness(){         //function for checking the whether it is sorted or not.
    int flag = 0;
    struct node *nextt,*temp = head;
    nextt = head->next;
    if(nextt->data >= temp->data){
        temp = nextt;
        nextt = nextt->next;
        while(nextt->next != head){
            if(nextt->data < temp->data){
                flag = 1;
                break;
            }
            flag = 2;
            temp = nextt;
            nextt = nextt->next;
        }
        if(nextt->next == head && flag == 2){
            if(nextt->data < temp->data){
                flag = 1;
            }
        }
    }
    else{
        temp = nextt;
        nextt = nextt->next;
        while(nextt->next != head){
            if(nextt->data > temp->data){
                flag = 1;
                break;
            }
            flag = 3;
            temp = nextt;
            nextt = nextt->next;
        }
        if(nextt->next == head && flag == 3){
            if(nextt->data > temp->data){
                flag = 1;
            }
        }
    }
    if(flag == 2)
        printf("\nThe linked list is in Increasing ordered");
    else if(flag == 3)
        printf("\nThe linked list is in Drecreasing ordered");
    else
        printf("\nThe linked list is not in ordered");
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(22);
    insert(20);
    insert(19);
    insert(5);
    insert(4);
    printf("Your Original Linked list is like this:: \n\t");
    print_list();
    check_orderness();
    return 0;
}
