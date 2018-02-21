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
/*void swap(){
    struct node *nodea,*nodeb,*temp;
    temp = head;
    int flag = 0;
    while(temp != NULL){
        if(temp->data == a){
            flag++;
            nodea = temp;
        }
        if(temp->data == b){
            flag++;
            nodeb = temp;
        }
        if(flag == 2)
            break;
        temp = temp->next;
    }
    int swap;
    swap = nodea->data;
    nodea->data = nodeb->data;
    nodeb->data = swap;
}*/

void swap2(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(){              //function for pairwise elements swapping of a list.
    int c;
    struct node *prev=head,*cur;
    cur = head->next;
    while(prev != NULL){
        swap2(&prev->data,&cur->data);
        prev = cur->next;
        if(prev->next != NULL)
            cur = prev->next;
        else
            break;
    }
}
int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);
    printf("Your Original List is::\n\t");
    print_list();
    swap();
    printf("\nYour List after swapping pairwise elements is::\n\t");
    print_list();
    return 0;
}
