#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insert(struct node *head,int data){        //function to insert element at beginning and return head pointer.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = head;
    head = newnode;
    return head;
}
void print_list(struct node *head){             //function for printing a list elements.
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}
int find_length(struct node *head){                             //function to return length of a list.
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void equality_check(struct node *head1,struct node *head2){     //function for comparing two linked list.
    int count1,count2,l2,l1 = find_length(head1);
    struct node *flag;
    l2 = find_length(head2);
    count1 = count2 = 0;
    if(l1 != l2)                                                //first condition for 2 list equal.
        printf("\nThe list1 and list2 are not equal as size of lists are not equal.\n");
        break;
    else{
        struct node *start1=head1,*start2;
        while(start1 != NULL){                  //this while loop compare the content of first list with contents of 2nd list.
            start2 = head2;
            while(start2 != NULL){
                if(start2->data == start1->data){
                    count1++;
                    break;
                }
                start2 = start2->next;
            }
            start1 = start1->next;
        }
        /* If repetition is present */
        start2 = head2;
        while(start2 != NULL){                  //this while loop compare the content of second list with contents of 1st list.
            start1 = head1;
            while(start1 != NULL){
                if(start1->data == start2->data){
                    count2++;
                    break;
                }
                start1 = start1->next;
            }
            start2 = start2->next;
        }
    }
    if(count1 == count2){
        printf("\nThe list1 and list2 are equal in size as well as content(value)\n");
    }
    else
        printf("\nThe list1 and list2 are equal but (%d-%d) = %d content(value) are different\n",count1,count2,count1-count2);
}
int main(){
    int l;
    struct node *head0,*head = NULL;
    head0 = NULL;
    head = insert(head,56);
    head = insert(head,56);
    head = insert(head,56);
    head = insert(head,56);
    head = insert(head,56);
    head0 = insert(head0,56);
    head0 = insert(head0,56);
    head0 = insert(head0,56);
    head0 = insert(head0,56);
    head0 = insert(head0,56);
    printf("Your Original Linked list1 is like this:: \n\t");
    print_list(head);
    printf("\nYour Original Linked list2 is like this:: \n\t");
    print_list(head0);
    equality_check(head,head0);
    return 0;
}
