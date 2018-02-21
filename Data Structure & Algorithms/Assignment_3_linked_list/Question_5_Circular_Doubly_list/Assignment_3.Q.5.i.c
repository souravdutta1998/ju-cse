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
    while(temp->next != head){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("->%d",temp->data);
    temp = temp->next;
    printf("\tCircular head = %d...\n",temp->data);
}

void insert_begin(int data){        //function for inserting data at the beginning.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
    }
    else{
        newnode->next = head;
        head->previous = newnode;

        struct node *temp=head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->previous = temp;
    }
    head = newnode;
    printf("Now after inserting %d at beginning, the list is :\n\t",data);
    print_list();
}

void insert_nth_order(int data,int arrang){             //function for inserting data in a sorted list.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *prev = NULL,*tamp,*temp = head;
    if(arrang == 2){
        while(temp->data <= data){
            prev = temp;
            temp = temp->next;
            if(prev->next == head)
                break;
        }
        newnode->next = temp;
        temp->previous = newnode;

        if(prev != NULL){
            prev->next = newnode;
            newnode->previous = prev;
        }
        else{
            struct node *tamp=head;
            while(tamp->next != head)
                tamp = tamp->next;

            tamp->next = newnode;
            newnode->previous = tamp;

            head = newnode;
        }
        printf("Now after inserting %d ,the Increasing ordered linked list is :\n\t",data);
        print_list();
    }
    else if(arrang == 3){
        while(temp->data >= data){
            prev = temp;
            temp = temp->next;
            if(prev->next == head)
                break;
        }
        newnode->next = temp;
        temp->previous = newnode;

        if(prev != NULL){
            prev->next = newnode;
            newnode->previous = prev;
        }
        else{
            struct node *tamp=head;
            while(tamp->next != head)
                tamp = tamp->next;

            tamp->next = newnode;
            newnode->previous = tamp;

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
    prev = NULL;
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
        struct node *tamp=head;
        while(tamp->next != head)
            tamp = tamp->next;

        tamp->next = newnode;
        newnode->previous = tamp;

        head = newnode;
    }
    printf("Now after inserting %d before the index %d,the list is :\n\t",data,pos);
    print_list();
}

void insert_end(int data){                  //function for inserting data at the end position.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        newnode->next = newnode;
        newnode->previous = newnode;
        head = newnode;
    }
    else{
        struct node *start = head;
        while(start->next != head){
            start = start->next;
        }
        start->next = newnode;
        newnode->previous = start;
        newnode->next = head;
        head->previous = newnode;
    }
    printf("Now after inserting %d at the end position,the list is :\n\t",data);
    print_list();
}

int check_orderness(){         //function for checking the whether it is sorted or not.
    int flag;
    struct node *nextt,*temp = head;
    nextt = temp->next;
    if(nextt->data >= temp->data){
        temp = nextt;
        nextt = nextt->next;
        while(temp->next != head){
            if(nextt->data < temp->data){
                flag = 1;
                break;
            }
            flag = 2;
            temp = nextt;
            nextt = nextt->next;
        }
        if(flag == 2 || temp->next == head)
            flag = 2;
    }
    else{
        temp = nextt;
        nextt = nextt->next;
        while(temp->next != head){
            if(nextt->data > temp->data){
                flag = 1;
                break;
            }
            flag = 3;
            temp = nextt;
            nextt = nextt->next;
        }
        if(flag == 3 || temp->next == head)
            flag = 3;
    }
    return flag;
}
int main(){
    head = NULL;       /*Unordered insertion*/
    int choice,num,index;
    printf("\nPress 0 for stop insertion in Circular Linked List.\n");
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
