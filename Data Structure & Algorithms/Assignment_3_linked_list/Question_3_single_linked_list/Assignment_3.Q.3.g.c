#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){              //function to insert element in a list.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void print_list(){      //function to print the list.
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}`
int check_orderness(){         //function for checking the whether it is sorted or not.
    int flag;
    struct node *nextt,*temp = head;
    nextt = temp->next;
    if(nextt->data >= temp->data){
        temp = nextt;
        nextt = nextt->next;
        while(nextt != NULL){
            if(nextt->data < temp->data){
                flag = 1;
                break;
            }
            flag = 2;
            temp = nextt;
            nextt = nextt->next;
        }
        if(flag == 2 || temp->next == NULL)
            flag = 2;
    }
    else{
        temp = nextt;
        nextt = nextt->next;
        while(nextt != NULL){
            if(nextt->data > temp->data){
                flag = 1;
                break;
            }
            flag = 3;
            temp = nextt;
            nextt = nextt->next;
        }
        if(flag == 3 || temp->next == NULL)
            flag = 3;
    }
    if(flag == 2)
        printf("\nThe linked list is in Increasing ordered");
    else if(flag == 3)
        printf("\nThe linked list is in Decreasing ordered");
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
