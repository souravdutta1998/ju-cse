#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};
struct Queue *front,*rear;

struct Queue *create_queue(int data){
    struct Queue *newnode;
    if((newnode=(struct Queue*)malloc(sizeof(struct Queue)))==NULL)
    perror("Malloc error");
    else
    {
        newnode->data=data;
        newnode->next=NULL;
    }

    return newnode;
}

int is_empty(){
    return (front == NULL && rear == NULL);
}

void enQueue(int data){
    struct Queue *queue = create_queue(data);

    if(front == NULL && rear == NULL){
        front = rear = queue;
        return;
    }
    struct Queue *temp=front;
    while(temp->next != NULL)
            temp = temp->next;


    temp->next = queue;
    rear = queue;

}

void print_queue(){
    if(is_empty()){
        printf("The queue is Empty.\n");
        exit(0);
    }

    struct Queue *mov=front;
    printf("(Front value)");
    while(mov != NULL){
        printf("->%d ",mov->data);
        if(mov->next == NULL)
            printf("(Rear value)\n");
        mov = mov->next;
    }
}

int deQueue(){
    if(is_empty()){
        printf("The queue is Empty.\n");
        exit(0);
    }

    struct Queue *del=front;
    int rtn = del->data;
    front = del->next;
    free(del);

    return rtn;
}

int main(){
    front = rear = NULL;
    enQueue(67);
    enQueue(8);
    enQueue(17);
    enQueue(4);
    enQueue(37);
    enQueue(1);
    printf("The Queue (FIFO) in Linked list form is:\n\t");
    print_queue();

    printf("\nThe 1st element from Queue list is %d\n",deQueue());
    print_queue();
    return 0;
}
