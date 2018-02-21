#include<stdio.h>
#include<stdlib.h>
#define max 30

int list[max];

void read_list(){
    int ch;
    while(1){
            printf("Choose 0 to exit and 1 to continue:\n");
            scanf("%d",&ch);
            if(ch == 1){
                   int x,y;
                   printf("Input the value and position no.(less or equal to 10) :\n");
                   scanf("%d %d",&x,&y);
                   list[avail].value == x;
                   list[avail].info == y;
                   avail++;
            else if(ch == 0){
                   break;
            }
}
void print_list(){
    index = 0;
    while(list[index].info != -1){
        printf("%d -",list[index].value);
        index= list[index].info;
    }
    printf("%d",list[index].value);
}
void empty_check_list(){
      int index = 0;
      if(list[index].info == -1){
        printf("List has one member.\n");
      }
      else if(list[index].info >= 0){
        printf("List has more than one value.\n");
      }
      else{
        printf("List is empty.\n");
      }
}
void insert_list(int pos){


}

int main(){
   int choice;
    while(1){
        // printing the options
        //printf("\nCurrent index(starts with 1) = %d\n",avail);
        printf("1. Read the list\n");
        printf("2. Print the list\n");
        printf("3. Check whether the list is empty or not\n");
        printf("4. Length of a list\n");
        printf("5. Delete an element at the nth position\n");
        printf("6. Search for key in a list\n");
        printf("7. Sort the list\n");
        printf("7. Retrieve the nth element of the list\n");
        printf("Enter  -1 to exit:\n ");
        printf("\n Enter the choice:\n");
        scanf("%d",&choice);

        switch(choice){

            case 1: {
                read_list(value,pos);
                break;
            }
            case 2: {
                print_list(pos);
                break;
	       }
            case 3: {
                empty_check_list(index);
                break;
            }

            case 4: {
                int index;
                printf("Enter the index of the list ");
                scanf("%d", &index);
                length_list(index);
                break;
            }
            case 5: {
                printf("Enter the list index: ");
                int index,pos;
                scanf("%d ",&index);
                printf("Give the position at which has to be deleted :\n");
                delete_list(index,pos);
                break;
            }
            case 6: {
                int index,key;
                printf("Give the index of list:\n");
                scanf("%d %",&index);
                printf("Give the value(key) which to be search :\n");
                search_list(index,key);
                break;
            }
            case 7: {
                int index;
                printf("Give the index of the list :\n");
                scanf("%d",index);
                sort_list(index);
            }
            default: {
                printf("Invalid option\n");
                break;
            }
       }
       if(choice == -1){
        break;
       }
    }
  return 0;
}
