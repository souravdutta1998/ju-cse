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
    newnode->previous = NULL;
    newnode->next = head;
    if(head!=NULL)
        head->previous = newnode;
    head = newnode;
}
void print_list(){
    struct node *temp = head;
    while(temp->next != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d\n\t(reverse/order)",temp->data);
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->previous;
    }
}
void remove_duplicate(){
    int num;
    struct node *prev,*nextt,*temp2,*cur,*temp1 = head;
    while(temp1 != NULL){           /* node pointer temp1 moves to all node for each element in it.*/
        num = temp1->data;
        temp2 = head;
        while(temp2 != NULL){                       /*node pointer temp2 moves until it becomes Null pointer.*/
            if(temp2->data == temp1->data && temp1->next != temp2->next){             /*condition for two elements be copy of each other.*/
                prev = temp2->previous;                       /*prev node points to the node
                                                                    just previous to the copyied elements of a particular node.*/
                nextt = temp2->next;                           /*nextt node points to the node
                                                                    just next to the copyied elements of a particular node.*/
                prev->next = nextt;
                if(nextt != NULL)               /* if nextt is a NULL pointer then it is not necessary*/
                    nextt->previous = prev;
                cur = temp2;
                free(cur);
                temp2 = prev;
            }
            temp2 = temp2->next;        /*Node points to next extended option.*/
        }
        temp1 = temp1->next;            /*Node points to next extended option.*/
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(6);
    insert(16);
    insert(56);
    insert(56);
    insert(16);
    insert(56);
    insert(6);
    printf("Your Original Linked list is like this:: \n\t");
    print_list();
    remove_duplicate();
    printf("\nThe list after removing of all copies of all element if present is:\n\t");
    print_list();
    return 0;
}
