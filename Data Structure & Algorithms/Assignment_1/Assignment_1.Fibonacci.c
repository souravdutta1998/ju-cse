#include<stdio.h>

int find_fib(int n){            //Iterative Function.
    if(n == 1 || n == 2)
        return 1;
    int i,first=1,second=1,next;
    for(i=3;i<=n;i++){
        next = first+second;
        first = next;
        second = first;
    }
    return next;
}

int find_fib_rec(int n){        //recursive function
    if(n == 1 || n ==2)
        return 1;
    else
        return(find_fib_rec(n-1)+find_fib_rec(n-2));        //Binary recursion call.
}

int main(){
    int n;
    //printf("Enter the number for finding that factorial:\n");
    //scanf("%d",&n);
    n = 20;
    printf("The %d(th) term in Fibonacci is %d\n",n,find_fib(n));

}
