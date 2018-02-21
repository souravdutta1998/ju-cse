#include<stdio.h>
#include<string.h>

struct stack{
    char opr[25];
    int top;
};
struct stack s; //stack declaration of size 20.   //initialization of top value.

int is_empty(){      //function to check stack is empty or not.
    if(s.top == -1)
        return 1;
    else
        return 0;
}
int priority(char o){   //function to define priority of operands.
    if(o == '(')
        return 0;
    if(o == '+' || o == '-')
        return 1;
    if(o == '*' || o == '/')
        return 2;
}
int is_higher(char o){      //function to compare operand priority for first calculation.
    int a;
    if(is_empty())
        return 1;
    else{
        a = s.top;
        while(a >= 0){
            if(priority(o) <= priority(s.opr[a]))
            return 0;
            a--;
        }
    }
}
char pop(){     //function to delete a top member of a stack.
    if(is_empty())
        return -1;
    else
        return s.opr[s.top--];
}
void push(char o){      //function to store a operands in the top position
    s.opr[++s.top] = o;
}
int is_open(){      //function to check the presence of open parenthesis.
    if(is_empty){
        return 0;
    }
    int flag=0,a = s.top;
    while(1){
        if(s.opr[a] == '('){
            flag = 1;
            break;
        }
        a--;
    }
    if(flag)
        return 0;
    else
        return 1;
}
int main(){
    s.top = -1;
    char exp[25]={'(','A','+','B','*','C',')','*','(','D','+','E',')'};
    //printf("Enter the expression :: ");
    //scanf("%s",exp);
    char x;
    int i=0,j;
    printf("InFix expression(%d) = ",strlen(exp));
    for(j=0;j<strlen(exp);j++){
        printf("%c",exp[j]);
    }
    printf(" and,\nPostFix conversion is = ");
    while(i<strlen(exp)){
        if(isalnum(exp[i]))     //isalnum(x) return non-zero value if x is a alphabet or digit.
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')'){
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else{
            if(!is_higher(exp[i]) && is_open())
                printf("%c",pop());
            else{
                push(exp[i]);
            }
        }
        //printf("\n->i= %d,s[top] = %c top = %d exp=%c",i,s[top],top,exp[i]);
        i++;
    }
    while(!is_empty()){
        printf("%c",pop());
    }
    return 0;
}
/*
#include<stdio.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}*/
