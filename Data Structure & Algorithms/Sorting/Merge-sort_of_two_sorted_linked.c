#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head1;
struct node* head;
struct node* head0;
void Insert(struct node** head11, int b){  //insert the new value to head.
    struct node* num = (struct node*)malloc(sizeof(struct node));
    num->data = b;
    num->next = NULL;
    if(*head11 != NULL){
        num->next = *head11;
    }
    *head11 = num;
}
struct node* merge(struct node* m1, struct node* m2){
    struct node* start;
    struct node* result;
    head1 = NULL;
    while(m1 != NULL && m2 != NULL){
        result = (struct node*)malloc(sizeof(struct node));
        if(m1->data < m2->data && m1 != NULL && m2 != NULL){
            result->data = m1->data;
            result->next = NULL;
            if(head1 == NULL){
                 head1 = result;
            }
            else{
                 start = head1;
                 while(start->next != NULL){
                      start = start->next;
                 }
                 start->next = result;
            }
            m1 = m1->next;

         }
         else if(m1->data >= m2->data && m1 != NULL && m2 != NULL){
            result->data = m2->data;
            result->next = NULL;
            if(head1 == NULL)
                 head1 = result;
            else{
                 start = head1;
                 while(start->next != NULL){
                      start = start->next;
                 }
                 start->next = result;
            }
            m2 = m2->next;
         }
     }
    if(m1 != NULL){
        result = (struct node*)malloc(sizeof(struct node));
        result->data = m1->data;
        result->next = NULL;
        start = head1;
        if(head1 == NULL)
            head1 = result;
        else{
            while(start->next != NULL){
                 start = start->next;
            }
            start->next = result;
        }
    }
    if(m2 != NULL){
        result = (struct node*)malloc(sizeof(struct node));
        result->data = m2->data;
        result->next = NULL;
        start = head1;
        if(head1 == NULL)
            head1 = result;
        else{
            while(start->next != NULL){
                 start = start->next;
            }
            start->next = result;
        }
    }
    return head1;
}
int main(){
    head = NULL;
    head0 = NULL;
    Insert(&head,9);
    Insert(&head,6);
    Insert(&head,2);
    Insert(&head,1); //created a ordered linked list head = {1,2,6,9}
    Insert(&head0,11);
    Insert(&head0,8);
    Insert(&head0,7); //create another ordered linked list ={7,8,11}
    struct node* temp = head;
    while(temp != NULL){
        printf("-> %d ",temp->data); //Print the first linked list.
        temp = temp->next;
    }
    printf("\n");
    struct node* tem = head0;
    while(tem != NULL){
        printf("-> %d ",tem->data); //print the second linked list.
        tem = tem->next;
    }
    printf("\n");
    printf("The new list after merging are:\n");
    head1 = merge(head,head0); // returned head node from the function.
    while(head1 != NULL){
        printf("-> %d ",head1->data);
        head1 = head1->next;
    }

    return 0;
}
