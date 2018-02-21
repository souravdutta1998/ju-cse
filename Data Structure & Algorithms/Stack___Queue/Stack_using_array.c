#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20

struct Stack{
    int top;
    int val[MAX];
};
typedef struct Stack *stack;
stack create_stack(){
    stack p;
    if ((p = (stack) malloc(sizeof(struct Stack)))== NULL){
        printf("Memory allocation error\n");
        exit(0);
    }
    p->top = -1 ;
    return p;
}
void s_dispose (stack s){
    if (s != NULL)
        free(s);
}
int s_empty(stack s){
    return (s->top == -1);
}

int s_full(stack s){
    return (s->top == MAX-1);
}

void push(stack s,int e){
    if(!(s_full(s)))
        s->val[++(s->top)] = e;
    else
        printf("Stack overflow error\n");
}

void print_stack(stack s){
    int i = s->top;
    printf("Top->\t%d\n",s->val[i--]);
    while(i >= 0){
        printf("\t%d\n",s->val[i]);
        i--;
    }
}
int pop(stack s){
    if(!(s_empty(s)))
        return s->val[(s->top)--];
    else{
        printf("Stack underflow error\n");
        exit(0);
    }
}

int main(){
    stack s = create_stack();
    push(s,45);
    push(s,8);
    push(s,71);
    push(s,45);
    push(s,8);
    push(s,71);
    print_stack(s);
    printf("The pop elements is %d\n",pop(s));

    return 0;
}
