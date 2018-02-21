#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head;

void print_list(){              //function for printing the list.
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

void insert_begin(int data){        //function for inserting data at the beginning.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->previous = NULL;
    newnode->next = head;
    if(head!=NULL)
        head->previous = newnode;
    head = newnode;
    printf("Now after inserting %d at beginning, the list is :\n\t",data);
    print_list();
}

void insert_nth_order(int data,int arrang){             //function for inserting data in a sorted list.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *nextt,*prev=NULL,*temp = head;
    if(arrang == 2){
        while(temp->data <= data){
            prev = temp;
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp == NULL)
            newnode->next = NULL;
        else{
            newnode->next = temp;
            temp->previous = newnode;
        }
        if(prev != NULL){
            prev->next = newnode;
            newnode->previous = prev;
        }
        else{
            newnode->previous = NULL;
            head = newnode;
        }
        printf("Now after inserting %d ,the Increasing ordered linked list is :\n\t",data);
        print_list();
    }
    else if(arrang == 3){
        while(temp->data >= data){
            prev = temp;
            temp = temp->next;
            printf("prev = %d ",prev->data);
            if(temp == NULL)
                break;
        }
        if(temp == NULL)
            newnode->next = NULL;
        else{
            newnode->next = temp;
            temp->previous = newnode;
        }
        if(prev != NULL){
            prev->next = newnode;
            newnode->previous = prev;
        }
        else{
            newnode->previous = NULL;
            head = newnode;
        }
        printf("Now after inserting %d ,the Decreasing ordered linked list is :\n\t",data);
        print_list();
    }
}

void insert_nth(int data,int pos){              //function for inserting data at the nth node in a unsorted list.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    int count = 1;
    struct node *prev ,*nextt = head;
    while(count < pos){
        count++;
        nextt = nextt->next;              //at the end of this loop prev points to node before the nth node which is pointed through next node.
    }
    prev = nextt->previous;
    newnode->next = nextt;
    nextt->previous = newnode;
    if(prev != NULL){
        prev->next = newnode;
        newnode->previous = prev;
    }
    else{
        newnode->previous = NULL;
        head = newnode;
    }
    printf("Now after inserting %d before the index %d,the list is :\n\t",data,pos);
    print_list();
}

void insert_end(int data){                  //function for inserting data at the end position.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->previous = NULL;
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else{
        struct node *start = head;
        while(start->next != NULL){
            start = start->next;
        }
        newnode->previous = start;
        start->next = newnode;
    }
    printf("Now after inserting %d at the end position,the list is :\n\t",data);
    print_list();
}

int check_orderness(){          //function for checking the whether it is sorted or not.
    int flag = 0;
    struct node *nextt,*temp = head;
    nextt = head->next;
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
    return flag;
}
int main(){
    head = NULL;       /*Unordered insertion*/
    int choice,num,index;
    printf("\nPress 0 for stop insertion.\n");
    printf("Press 1 for insert at beginning.\n");
    printf("Press 2 for insert at nth node.\n");
    printf("Press 3 for insert at end position.\n");
    do{
        printf("\nEnter your data to be insert with insertion choice number:: ");
        scanf("%d %d",&num,&choice);
        if(choice == 1)
            insert_begin(num);
        else if(choice == 3)
            insert_end(num);
        else if(choice == 2){
            if(check_orderness() == 1){
                printf("Specify the node before you want to insert by giving index number:\n");
                scanf("%d",&index);
                insert_nth(num,index);
            }
            else
                insert_nth_order(num,check_orderness());
        }
        else
            break;
    }
    while(choice != 0);

    return 0;
}
