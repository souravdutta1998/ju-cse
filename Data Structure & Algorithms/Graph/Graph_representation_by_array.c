#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char V[] = { "ABCDEF" };

struct adjacency{
    int startIndex;
    int endIndex;
    int weight;
};
struct graph{
    int count;
    struct adjacency *array;
};

struct graph* createGraph(int V)
{
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->count = 0;
    g->array = (struct adjacency*)malloc(V*sizeof(struct adjacency));

    return g;
}

void display(struct graph *g){
    int i;
    for(i=0;i<g->count;i++){
        printf("\t%c(%d)\t----\t%c(%d) weight = %d\n",
               V[g->array[i].startIndex],g->array[i].startIndex,V[g->array[i].endIndex],g->array[i].endIndex,g->array[i].weight);
    }

}

void create_edge(struct graph *g,int st,int des,int wt){

    g->array[g->count].startIndex = st;
    g->array[g->count].endIndex = des;
    g->array[g->count].weight = wt;
    g->count++;

}

/*execution time : 45.536 s*/
int main(){
    struct graph *g = createGraph(9);

    create_edge(g,0,1,8);
    create_edge(g,0,2,4);
    create_edge(g,0,5,7);
    create_edge(g,1,2,4);
    create_edge(g,1,3,9);
    create_edge(g,2,3,1);
    create_edge(g,2,5,12);
    create_edge(g,3,4,5);
    create_edge(g,4,5,9);

    display(g);
    return 0;
}
