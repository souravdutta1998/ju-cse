#include<stdio.h>
#include<string.h>

struct stack{
    char opr[25];
    int top;
};
struct stack s; //stack declaration of size 20.
int top = -1;   //initialization of top value.

int is_empty(){      //function to check stack is empty or not.
    if(s.top == -1)
        return 1;
    else
        return 0;
}
int priority(char o){   //function to define priority of operands.
    if(o == ')')
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
            if(priority(o) < priority(s.opr[a]))
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
        if(s.opr[a] == ')'){
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
    char exp[25];//={'(','(','A','+','B',')','*','(','C','+','D',')','/','(','E','-','F',')',')','+','G'};
    printf("Enter the expression :: ");
    scanf("%s",exp);
    char res[25],x;
    int i=strlen(exp)-1,j;
    printf("InFix expression(%d) = ",strlen(exp));
    for(j=0;exp[j] != '\0';j++){
        printf("%c",exp[j]);
    }
    j = 0;
    int k;
    printf(" and,\nPrefix conversion is = ");
    while(i>=0){
        if(isalnum(exp[i]))    //isalnum(x) return non-zero value if x is a alphabet or digit.
            res[j++] = exp[i];
        else if(exp[i] == ')')
            push(exp[i]);
        else if(exp[i] == '('){
            k = s.top;
            while(1){
                x = s.opr[k];
                if(x != ')'){
                    res[j++] = pop();
                }
                else{
                    pop();
                    break;
                }
                k--;
            }
        }
        else{
            //printf("@here,is-higher = %d ,is-open = %d",is_higher(exp[i]),is_open());
            if(!is_higher(exp[i]) && is_open()){
                do{
                    x = pop();
                    res[j++] = x;
                }while(!is_higher(exp[i]));
            }
            else{
                push(exp[i]);
            }
        }
        //printf("\nnow,top = %d,first = %c",s.top,s.opr[s.top]);
        i--;
    }
    while(s.top >= 0){
        res[j] = pop();
    }
    i=j;
    while(i >= 0){
        printf("%c",res[i]);
        i--;
    }
    return 0;
}
