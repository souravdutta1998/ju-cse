#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
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
void sort_list(){
    int big,swap;
    struct node *cur=head,*temp,*start;
    while(cur->next != NULL){
        start = cur->next;
        big = cur->data;
        while(start != NULL){
            if(start->data <= big){
                big = start->data;
                temp = start;
            }
            start = start->next;
        }
        swap = temp->data;
        temp->data = cur->data;
        cur->data = swap;
        cur = cur->next;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(12);
    insert(56);        /*Ordered Increasing insertion */
    insert(200);
    insert(77);
    insert(6);
    printf("The Original list is:\n\t");
    print_list();
    sort_list();
    printf("\nThe sorted list of original list is:\n\t");
    print_list();
    return 0;
}
