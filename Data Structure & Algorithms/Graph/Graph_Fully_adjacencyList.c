#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Adjacency_list{
    int edge;
    struct Adjacency_list *next;
    //int weight;
};
struct Adjacency{
    struct Adjacency_list *head;
};
struct Graph{
    int V;
    struct Adjacency *array;
};

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct Adjacency*) malloc(V * sizeof(struct Adjacency));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

struct Adjacency_list *createAdjacency(int edge){
    struct Adjacency_list* adjacency_list = (struct Adjacency_list*) malloc(sizeof(struct Adjacency_list));
    adjacency_list->edge = edge;
    adjacency_list->next = NULL;
    return adjacency_list;
}

void Edge_link(struct Graph *g,int st,int des){
    struct Adjacency_list *temp = createAdjacency(st);
    temp->next = g->array[des].head;
    g->array[des].head = temp;

    temp = createAdjacency(des);
    temp->next = g->array[st].head;
    g->array[st].head = temp;
}

void display_graph(struct Graph *graph,char *alp){
    int i;
    printf("The representation of your directed graph through Adjacency List:\n");
    for(i=0;i<graph->V;i++){
        printf("Adjacency List of Vertex %c:\n",alp[i]);
        struct Adjacency_list *temp = graph->array[i].head;
        while(temp != NULL){
            printf("-->%c(%d)",alp[temp->edge],temp->edge);
            temp = temp->next;
        }
        printf("\n");
    }
}
/*Time = 0.012sec*/
int main(){
    char V[] = { "ABCDEF" };
    struct Graph *g = createGraph(strlen(V));
    Edge_link(g,0,1);
    Edge_link(g,0,2);
    Edge_link(g,0,5);
    Edge_link(g,1,2);
    Edge_link(g,1,3);
    Edge_link(g,2,3);
    Edge_link(g,2,5);
    Edge_link(g,3,4);
    Edge_link(g,4,5);

    display_graph(g,V);
    return 0;
}
