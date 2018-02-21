#include<stdio.h>
#include<stdlib.h>

struct hash{
    int value;
    int key;
    struct hash *next;
};
void display(struct hash ar[],int n){
    int i;
    printf("Value\tKey\n");
    for(i=0;i<n;i++){
        if(ar[i].value != -1){
            printf("%d\t%d ",ar[i].value,ar[i].key);
            if(ar[i].next != NULL){
                struct hash *ptr;
                ptr = ar[i].next;
                while(ptr != NULL){
                    printf("->%d",ptr->value);
                    ptr = ptr->next;
                }
            }
            printf("\n");
        }
    }
}
void insert(struct hash ar[],int size){
    int ins;
    printf("Enter the inserted elements: ");
    scanf("%d",&ins);
    if(ar[ins%size].value == -1){
        ar[ins%size].value = ins;
        ar[ins%size].key = ins%size;
    }
    else{
        struct hash *ptr,*newnode;
        newnode = (struct hash*)malloc(sizeof(struct hash));
        newnode->value = ins;
        newnode->key = ins%size;
        newnode->next = NULL;

        if(ar[ins%size].next == NULL)
            ar[ins%size].next = newnode;
        else{
            ptr = ar[ins%size].next;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
}
void search(struct hash ar[],int size){
    int num;
    printf("Enter the key u want to search:: ");
    scanf("%d",&num);
    if(ar[num%size].value == num && ar[num%size].next == NULL)
        printf("The key number %d is found in the table.It was at index %d\n",num,ar[num%size].key);
    else if(ar[num%size].value != num && ar[num%size].next != NULL){
        struct hash *ptr;
        int flag = 0;
        ptr = ar[num%size].next;
        while(ptr != NULL){
            if(ptr->value == num){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(flag){
            printf("The key number %d is found in the table.It was at index %d\n",num,ptr->key);
        }
        else
            printf("The searched key was not found.\n");
    }
    else
        printf("The searched key was not found.\n");

}
int main(){
    int size,i,j,x;
    printf("Enter the size of table: ");
    scanf("%d",&size);
    struct hash function[size];
    for(i=0;i<size;i++){
        function[i].value = -1;
        function[i].next = NULL;
    }
    printf("Enter the elements::\n");
    printf("Enter -1 to exit:\n");
    while(1){
        scanf("%d",&x);
        if(x == -1)
            break;
        function[x%size].value = x;
        function[x%size].key = x%size;
    }
    display(function,size);
    //insert(function,size);
    //insert(function,size);
    //insert(function,size);
    display(function,size);
    search(function,size);
    return 0;
}
