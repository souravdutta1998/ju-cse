#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct graph{
    int Index;
    struct graph *link;
    //int weight;
};
void display(struct graph *ar[],char alp[],int size){
    int i,k =0 ;
    printf("The representation of your directed graph through Adjacency List:\n");
    for(i=0;i<size;i++){
        if(ar[i]->link != NULL){
            printf("\t%c(%d)--",alp[ar[i]->Index],ar[i]->Index);
            struct graph *mov = ar[i]->link;
            while(mov != NULL){
                printf("-->%c(%d)",alp[mov->Index],mov->Index);
                mov = mov->link;
            }
            printf("\n");
        }
    }
}
/*Time = 74.44sec*/
int main(){
    char V[] = { "ABCDEF" };
    int size,i,end,j,last;
    i = 0;

    struct graph *g[strlen(V)];
    do{
        printf("Enter how many edges are linked with %c:: ",V[i]);
        scanf("%d",&end);

        struct graph *newgraph = (struct graph*)malloc(sizeof(struct graph));
        newgraph->Index = i;
        newgraph->link = NULL;
        g[i] = newgraph;

        printf("Give the endIndex of V[%d] = %c\n",i,V[i]);
        for(j=0;j<end;j++){
            scanf("%d",&last);

            struct graph *newgraph = (struct graph*)malloc(sizeof(struct graph));
            newgraph->Index = last;
            newgraph->link = NULL;

            struct graph *start=g[i];
            while(start->link != NULL)
                start = start->link;
            start->link = newgraph;
        }

        i++;
    }
    while(i<strlen(V));

    display(g,V,i);
    return 0;
}
