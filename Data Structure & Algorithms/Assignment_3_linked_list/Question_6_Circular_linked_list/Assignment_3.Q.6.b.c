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
    if(head == NULL)
        newnode->next = newnode;
    else{
        newnode->next = head;
        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newnode;
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
}

int find_length(){
    int count = 0;
    struct node *temp = head;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    return(count+1);
}
int main(){
    int l;
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original Circular Linked list is like this:: \n\t");
    print_list();
    l = find_length();
    printf("\nSize of list is %d\n",l);
    return 0;
}
