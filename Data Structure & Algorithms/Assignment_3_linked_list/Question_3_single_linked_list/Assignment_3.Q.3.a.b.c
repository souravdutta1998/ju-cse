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
struct node *search_key(int key){
    struct node *srch = head;
    while(srch->data != key)
        srch = srch->next;
    return srch;
}
void delete_key(struct node *key){
    int count = 1;
    struct node *prev,*next;
    prev = head;
    while(prev->next != key){
        count++;
        prev = prev->next;
    }
    printf("is present at Position no. %d\n",++count);
    next = key->next;
    prev->next = next;
    free(key);
}
int main(){
    head = NULL;       /*Unordered insertion
    insert(2);
    insert(7);
    insert(4);
    insert(12);
    insert(56);        */
                    /*Ordered Increasing insertion */
    insert(200);
    insert(77);
    insert(44);
    insert(12);
    insert(6);
    print_list();
    struct node *key = search_key(12);
    printf("\n\tKey->data = %d ",key->data);
    delete_key(key);
    print_list();
    return 0;
}
