#include<stdio.h>

int stack[20];
int top = -1;
int pop(){     //function to delete a top member of a stack.
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void push(int o){      //function to store a operands in the top position
    stack[++top] = o;
}
int operation(char o,int a,int b){
    if(o == '+' )
        return (a+b);
    if(o == '-' )
        return (a-b);
    if(o == '*' )
        return (a*b);
    if(o == '/' )
        return (a/b);
    else return -1;
}
int main(){
    int i;
    char eqt[12];
    printf("Give your equation in postfix form:: ");
    scanf("%s",eqt);
    i = sizeof(eqt)-1;
    int op1,op2,result;
    while(i>=0){
        if(isalnum(eqt[i]))
            push((eqt[i]-48));
        else{
            op1 = pop();
            op2 = pop();
            result = operation(eqt[i],op1,op2);
            push(result);
        }
        i--;
    }
    printf(" = %d", pop());
    return 0;
}
