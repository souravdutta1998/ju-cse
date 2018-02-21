#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node* next;
};

struct node *head;
struct node* init_l(struct node *cur){
    return NULL;
}
void print_list(struct node *head){
    if(empty_l(head))
        printf("The list is empty.\n");
    else{
        printf("\t");
        struct node *temp = head;
        while(temp != NULL){
            printf("->%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int empty_l(struct node *head){
    if(head != NULL)
        return 0;
    else
        return 1;
}

int attend_l(struct node *cur){
    if(cur->next == NULL)
        return 1;
    else
        return 0;
}

void insert_front(struct node *target,struct node *head0){
    target->next = head0;
    head = target;
    print_list(head);
}

void insert_after(struct node *target,struct node *prev){
    if(head == NULL)
        head = target;
    else{
        struct node *next,*start = head;
        while(start != prev){
            start = start->next;
        }
        next = prev->next;
        start->next = target;
        target->next = next;
    }
    print_list(head);
}

void delete_front(struct node *head){
    struct node *now,*del = head;
    now = del->next;
    head = now;
    free(del);
    print_list(head);
}

void delete_after(struct node *prev){
    struct node *next1,*next2,*start = head;
    next1 = prev->next;
    next2 = next1->next;
    prev->next = next2;
    free(next1);
    print_list(head);
}
int main(){
    int ch;
    printf("Press 0 to exit\n");
    printf("Press 1 for initialize a list.\n");
    printf("Press 2 for insert the node as the first node of the list.\n");
    printf("Press 3 for insert the node after a particular node.\n");
    printf("Press 4 for check if the list is empty or not.\n");
    printf("Press 5 for check if a particular node points to last node in the list or not.\n");
    printf("Press 6 for delete the first elements of the list.\n");
    printf("Press 7 for delete the node after a particular node.\n");
    printf("Enter your choice:: ");
    scanf("%d",&ch);
    do{
        switch(ch){
            case 1:{
                head = init_l(head);
                break;
            }
            case 2:{
                int num;
                printf("Enter your element in integer form:: ");
                scanf("%d",&num);
                struct node *list;
                list = (struct node*)malloc(sizeof(struct node));
                if(list==NULL)
                    perror("malloc error");
                list->data = num;
                list->next = NULL;
                insert_front(list,head);
                break;
            }
            case 3:{
                int i,num,in;
                printf("Enter your element in integer form and give node index after the node to be insert(>=1):\n");
                scanf("%d %d",&num,&in);
                struct node *list,*start=head;
                list = (struct node*)malloc(sizeof(struct node));
                list->data = num;
                list->next = NULL;
                do{
                    i = 1;
                    while(i<in){
                        start = start->next;
                        i++;
                    }
                    if(start == NULL){
                        printf("Give correct index as your given index not exit in your list.\n");
                        scanf("%d",&in);
                    }
                    else
                        break;
                }
                while(1);
                insert_after(list,start);
                break;
            }
            case 4:{
                if(empty_l(head))
                    printf("The list is empty.\n");
                else
                    printf("The list is not empty.\n");
                break;
            }
            case 5:{
                int i,in;
                printf("Enter the node index you want to check if its points to last node of the list:\n");
                scanf("%d",&in);
                struct node *start=head;
                i = 1;
                while(i<in){
                    start = start->next;
                    i++;
                }
                if(attend_l(start))
                    printf("Yes, the node points to last node of you list.\n");
                else
                    printf("No, the node do not points to last node of you list.\n");
                break;
            }
            case 6:{
                delete_front(head);
                break;
            }
            case 7:{
                int i,in;
                printf("Enter the node index after the node to be deleted:\n");
                scanf("%d",&in);
                struct node *start=head;
                do{
                    i = 1;
                    while(i<in){
                        start = start->next;
                        i++;
                    }
                    if(start->next == NULL || start == NULL){
                        printf("The index you entered is not correct as next node is not present.\n");
                        printf("Again , Enter the node index after the node to be deleted:\n");
                        scanf("%d",&in);
                    }
                    else{
                        delete_after(start);
                        break;
                    }
                }
                while(1);
                break;
            }
            default:{
                printf("Enter Valid choice::,");
                break;
            }
        }
        printf("Enter your next choice:: ");
        scanf("%d",&ch);
        if(!ch)
            break;
    }while(1);
    return 0;
}
