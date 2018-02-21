#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

struct Queue{
    int front,rear,size;
    unsigned int capacity;
    int *array;
};


struct Queue *create_queue(unsigned int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->capacity = capacity;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity*sizeof(int));
    return queue;
}

void print_Queue(struct Queue *q){
    if(isEmpty(q))
        return;
    int i;
    for(i=q->front;i<q->size;i++){
        printf("| %d |",q->array[i]);
    }
    printf("\n");
}

int isFull(struct Queue *q){
    return (q->size == q->capacity);
}

int isEmpty(struct Queue *q){
    return (q->size == 0);
}

void enQueue(struct Queue *q,int data){
    if(isFull(q))
        return;
    q->rear = (q->rear+1)%q->capacity;
    q->array[q->rear] = data;
    q->size++;
}

int find_front(struct Queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->array[q->front];
}

int find_rear(struct Queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->array[q->rear];
}

int left_capacity(struct Queue *q){
    return (q->capacity - q->size);
}

int deQueue(struct Queue *q){
    if(isEmpty(q))
        return INT_MIN;
    int data = q->array[q->front];
    q->front = (q->front+1)%q->capacity;
    q->size--;
    return data;
}

int main(){
    struct Queue *queue = create_queue(10);
    enQueue(queue,3);
    enQueue(queue,56);
    enQueue(queue,13);
    enQueue(queue,6);
    enQueue(queue,30);
    enQueue(queue,5);
    print_Queue(queue);
    printf("Remaining capacity = %d\n",left_capacity(queue));
    //printf("Front element = %d\n",find_front(queue));
    //printf("Rear element = %d\n",find_rear(queue));
    printf("Deleted element = %d\n",deQueue(queue));
    print_Queue(queue);
    printf("Remaining capacity = %d\n",left_capacity(queue));
    //printf("Front element = %d\n",find_front(queue));
    //printf("Rear element = %d\n",find_rear(queue));
    return 0;
}
