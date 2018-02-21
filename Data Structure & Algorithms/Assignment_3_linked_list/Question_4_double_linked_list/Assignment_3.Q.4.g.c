#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
void insert(int data){              //function to insert element in a list.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;
}
void print_list(){      //function to print the list.
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
void check_orderness(){         //function for checking the whether it is sorted or not.
    int flag = 0;
    struct node *next,*temp = head;
    next = head->next;
    if(next->data >= temp->data){
        temp = next;
        next = next->next;
        while(next != NULL){
            if(next->data < temp->data){
                flag = 1;
                break;
            }
            flag = 2;
            temp = next;
            next = next->next;
        }
        if(flag == 2 || temp->next == NULL)
            flag = 2;
    }
    else{
        temp = next;
        next = next->next;
        while(next != NULL){
            if(next->data > temp->data){
                flag = 1;
                break;
            }
            flag = 3;
            temp = next;
            next = next->next;
        }
        if(flag == 3 || temp->next == NULL)
            flag = 3;
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
    insert(12);
    insert(19);
    insert(40);
    insert(59);
    insert(64);
    printf("Your Original Linked list is like this:: \n\t");
    print_list();
    check_orderness();
    return 0;
}
