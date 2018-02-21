#include<stdio.h>
#include<string.h>
#define max 25

struct stack{
    char opr[max][max];
    int top;
};
struct stack s;
char *pop(){     //function to delete a top member of a stack.
    if(s.top == -1)
        return -1;
    else
        return s.opr[s.top--];
}
void push(char o){      //function to store a operands in the top position
    s.top++;
    s.opr[s.top][1] = { "o" };
    printf(" stored-> %s\n",s.opr[s.top][0]);
}
void push1(char *o,int l){      //function to store a operands in the top position
    int i;
    s.top++;
    for(i=0;i<l;i++)
        s.opr[s.top][i] = o[i];
    printf(" stored-> %s\n",s.opr[s.top]);
}
void operation(char o,char *a, char *b,int l1,int l2){
    int j,i = 0;
    static char mul[max];
    mul[i++] = o;
    for(j=0;j<l1;j++)
        mul[i++] = a[j];
    for(j=0;j<l2;j++)
        mul[i++] = b[j];
    mul[i] = '\0';
    push1(mul,i);
}
int main(){
    s.top = -1;
    char *op1,*op2,*result,exp[max];
    printf("Enter your expression in post-fix form :: ");
    scanf("%s",exp);
    int i,l1,l2,l = strlen(exp);
    printf("length = %d",l);
    i =0;
    while(i < l){
        if(isalnum(exp[i]))
            push(exp[i]);
        else{
            op2 = pop();
            l1 = strlen(op2);
            op1 = pop();
            l2 = strlen(op1);
            operation(exp[i],op1,op2,l2,l1);
            printf("op1 = %c,op2 = %c,result = %c",op1,op2,result);
            //push(result);
        }
        i++;
    }

    return 0;
}
