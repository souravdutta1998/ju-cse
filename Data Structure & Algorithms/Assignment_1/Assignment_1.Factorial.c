#include<stdio.h>

int find_fact(int n){               //Iterative Function.
    int i,p=1;
    for(i=1;i<=n;i++){
        p *= i;
    }
    return p;
}

int find_fact_rec(int n){
    if(n == 0)
        return 1;
    else
        return(n*find_fact_rec(n-1));
}

int main(){
    int n;
    //printf("Enter the number for finding that factorial:\n");
    //scanf("%d",&n);
    n = 10;
    printf("The factorial of %d is %d\n",n,find_fact(n));

}
