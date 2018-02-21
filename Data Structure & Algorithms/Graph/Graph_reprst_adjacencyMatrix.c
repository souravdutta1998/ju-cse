#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
char V[] = { "ABCDEFGHI" };

struct MST{                 //structure of a Edges.
    int v1;
    int v2;
    int weight;
};
void display(int ar[strlen(V)][strlen(V)] ,char alp[]){         //function for printing the graph in Adjacency Matrix form.
    int i,j =0;
    printf("The representation of your graph through Adjacency Matrix form:\n");
    printf("---------------------------------------------------------\n");
    printf(" Edge\t|");
    for(i=0;i<strlen(V);i++){
        printf("%c\t",alp[i]);
    }
    printf("\n_________________________________________________\n");
    for(i=0;i<strlen(V);i++){
        printf("  %c\t|",alp[i]);
        for(j=0;j<strlen(V);j++){
            printf("%d\t",ar[i][j]);
        }
        printf("\n");
    }

}

int min(int key[],bool dis_set[]){          //function for finding minimum distance of vertex from source Up-to from list of visited vertex.
    int i,minim = INT_MAX,min_index;
    for(i=0;i<strlen(V);i++){
        if(dis_set[i] == false && key[i] <= minim){
            minim = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void swap_mst(struct MST *a,struct MST *b){     //swapping two struct vertex Edges.
    struct MST temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort_weight_edge(struct MST *mst,int k){       //function for sorting(Selection Sort) the struct MST array on basis of weight.
    int i,j,min,min_index;
    for(i=0;i<k-1;i++){
        min = mst[i].weight;
        min_index = i;
        j = i+1;
        while(j < k){
            if(mst[j].weight < min){
                min = mst[j].weight;
                min_index = j;
            }
            j++;
        }
        if(min_index != i)
            swap_mst(&mst[i],&mst[min_index]);
    }
}

int check_vertex(int count[],struct MST m){      //function for checking cycles of edges.
    //printf("count[v1 = %d] = %d count[v2 = %d] = %d\t",m.v1,count[m.v1],m.v2,count[m.v2]);
    if(count[m.v1] <= 1 && count[m.v2] <= 1){
        if((count[m.v1] != 1 || count[m.v2] != 1) )
            return 1;
    }
    return 0;
}

void kruskals_algorithm(int g[strlen(V)][strlen(V)]){       //function for Finding MST by Kruskal's Algorithm.
    int i,j,k=0,min_index,min;
    struct MST mst[20];

    for(i=0;i<strlen(V);i++){
        for(j=i;j<strlen(V);j++){
            if(g[i][j] != 0){                   //storing weighted edges in struct MST type array.
                mst[k].v1 = i;
                mst[k].v2 = j;
                mst[k].weight = g[i][j];
                k++;
            }
        }
    }
    sort_weight_edge(mst,k);            //sort the weighted edges.

    bool check[k];                  //boolean function for checking the cycles of edges.
    int count[strlen(V)];               //count no of adjacent edges of all Vertex.
    for(i=0;i<k;i++)
        check[i] = false;               //initialization of all cycles condition.
    for(i=0;i<strlen(V);i++)
        count[i] = 0;                   //initialization of no. of adjacency edges.

    for(i=0;i<k;i++){
        if(check_vertex(count,mst[i])){     //cycle condition is checked by calling check_vertex() function.
            check[i] = true;                    //update the edges.
            //printf("include = %d--%d\n",mst[i].v1,mst[i].v2);
            count[mst[i].v1]++;                    //incrementing no. of adjacent edges of vertex.
            count[mst[i].v2]++;
        }
    }
    for(i=0;i<k;i++){
        if(check[i] == false){
            check[i] = true;
            //printf("include = %d--%d\n",mst[i].v1,mst[i].v2);
            break;
        }
    }
    int min = INT_MIN,p;
    for(i=0;i<k;i++){
        if(mst[i].weight < min && check[i] == true){
            min = mst[i].weight;
            p = i;
        }
    }


    /*Printing the Edges.*/

    printf("Thus By Kruskal's Algorithm,the minimum spanning tree contained these edges:\n");
    printf("Vertex1\tVertex2\tWeight\n");
    for(i=0;i<k;i++){
        if(check[i] == true)
            printf("%d\t%d\t%d\n",mst[i].v1,mst[i].v2,mst[i].weight);
    }

}

void print_prims(int parent[],int g[strlen(V)][strlen(V)]){     //function for printing MST obtained by Prim's Algorithm.
    int i,j;
    printf("Thus By Prim's Algorithm,the minimum spanning tree contained these edges:\n");
    for(i=1;i<strlen(V);i++){
        printf("%c -- %c weight = %d\n",V[parent[i]],V[i],g[i][parent[i]]);
    }
}

void print_dijkstras(int min_dis[],int parent[]){           //function for printing MST obtained by Dijkstra's Algorithm.
    int i,j,sum=0;
    printf("Thus By Dijkstras's Algorithm,the minimum spanning tree contained these edges:\n");
    for(i=1;i<strlen(V);i++){
        sum += fabs(min_dis[i]-min_dis[parent[i]]);
        printf("%c -- %c @Weight = %d\n",V[i],V[parent[i]],(int)fabs(min_dis[i]-min_dis[parent[i]]));
    }
    printf("Weight of Minimum Spanning Tree = %d\n",sum);
}

void prims_algorithm(int g[strlen(V)][strlen(V)]){      //Prim's Algorithm for MST.
    int i,j,u,v;
    int key[strlen(V)];         //for storing the next traversal Vertex from its parent Vertex.
    int parent[strlen(V)];          //for storing index of parent Vertex of a particular Vertex.
    bool prims_set[strlen(V)];          //boolean array for each Vertex for checking the visited flag value.

    for(i=0;i<strlen(V);i++){           //initialization of key value and flag value for each Vertex.
        key[i] = INT_MAX;
        prims_set[i] = false;
    }

    key[0] = 0;                 //starts with min index Vertex with 0.
    parent[0] = -1;            //starting Vertex have not any parent vertex so its value is -1.

    for(j=0;j<strlen(V);j++){
        u = min(key,prims_set);             //choosing the minimum weighted linked vertex.
        prims_set[u] = true;               //marks that vertex by boolean flag value(true).

        for(v=0;v<strlen(V);v++){           //searching for next minimum weighted vertex linked to u and yet not visited.
            if(g[u][v] && prims_set[v] == false && g[u][v] < key[v])
                parent[v] = u,key[v] = g[u][v];             //storing the parent vertex and weight of next linked vertex.
        }

    }
    print_prims(parent,g);            //printing the MST.
}

void dijkstras_algorithm(int g[strlen(V)][strlen(V)]){          //dijkstra's Algorithm for MST.
    int i,j,u,v;
    int M_dist[strlen(V)];                  //for updating minimum distance from source.
    int parent[strlen(V)];                  //for storing predecessor parent of a vertex.
    bool dis_set[strlen(V)];                //boolean array for each Vertex for checking the visited flag value.

    for(i=0;i<strlen(V);i++){                  //initialization of minimum distance from source and flag value for each Vertex.
        M_dist[i] = INT_MAX;
        dis_set[i] = false;
    }

    M_dist[0] = 0;                      //starts with min index Vertex with 0.
    parent[0] = -1;                 //starting Vertex have not any parent vertex so its value is -1.

    for(j=0;j<strlen(V)-1;j++){
        u = min(M_dist,dis_set);                //choosing the minimum weighted linked vertex.
        dis_set[u] = true;                      //starting Vertex have not any parent vertex so its value is -1.

        for(v=0;v<strlen(V);v++){
            /*Condition for update of minimum dis from source if it is not yet visited , there is an edge from u to v
                        and total weight of path from source to  v through u is
                            smaller than current value of M_dist[v]*/
            if(g[u][v] && M_dist[u] != INT_MAX && dis_set[v] == false && M_dist[u]+g[u][v] < M_dist[v]){
                M_dist[v] = M_dist[u] + g[u][v],parent[v] = u;
            }
        }

    }
    print_dijkstras(M_dist,parent);         //Printing the MST.
}

void find_spanning_tree(int g[strlen(V)][strlen(V)],int tree[strlen(V)],bool flag[strlen(V)] ,int present,int k,int count[strlen(V)]){
    int j,next;
    for(j=0;j<strlen(V);j++){
        if(g[present][j] != 0){
            next = j;
            if(flag[next] == false){
                tree[k] = j;
                //printf("Store = %c\t",V[tree[k]]);
                flag[j] = true;
                count[k-1] = g[present][j];
                //printf("g[%d][%d] = %d count = %d Visiting vertex = %c\n",present,j,g[present][j],count[k-1],V[present]);
                present = next;
                k++;
                //printf("j = %d k = %d next = %c\n",j,k,V[present]);
                find_spanning_tree(g,tree,flag,present,k,count);
            }
        }
    }

}

void graph_traversal(int g[strlen(V)][strlen(V)]){
    int i,tree[strlen(V)],count[strlen(V)];
    bool flag[strlen(V)];
    for(i=0;i<strlen(V);i++){
        flag[i] = false;
        tree[i] = INT_MIN;
    }
    find_spanning_tree(g,tree,flag,5,0,count);
    int sum = 0;
    for(i=0;i<strlen(V)-1;i++){
        sum += count[i];
        printf("%c - ",V[tree[i]]);
    }

    printf("%c\nAnd, Weight of spanning tree = %d",V[strlen(V)-1],sum);
}

void create_edge(int g[strlen(V)][strlen(V)],int st,int des,int weight){    //function for placing the weight in Adj. Matrix.
    g[st][des] = g[des][st] = weight;
}

/*execution time : 45.536 s*/
int main(){
    int size,end,j,k,pos,i;

    int graph_matrix[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                            {4, 0, 8, 0, 0, 0, 0, 11, 0},
                            {0, 8, 0, 7, 0, 4, 0, 0, 2},
                            {0, 0, 7, 0, 9, 14, 0, 0, 0},
                            {0, 0, 0, 9, 0, 10, 0, 0, 0},
                            {0, 0, 4, 14, 10, 0, 2, 0, 0},
                            {0, 0, 0, 0, 0, 2, 0, 1, 6},
                            {8, 11, 0, 0, 0, 0, 1, 0, 7},
                            {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    /*
    for(i=0;i<strlen(V);i++){
        for(j=0;j<strlen(V);j++)
            graph_matrix[i][j] = 0;
    }
    create_edge(graph_matrix,0,1,8);
    create_edge(graph_matrix,0,2,4);
    create_edge(graph_matrix,0,5,7);
    create_edge(graph_matrix,1,2,4);
    create_edge(graph_matrix,1,3,9);
    create_edge(graph_matrix,2,3,1);
    create_edge(graph_matrix,2,5,12);
    create_edge(graph_matrix,3,4,5);
    create_edge(graph_matrix,4,5,9);
    */
    //display(graph_matrix,V);

    //prims_algorithm(graph_matrix);
    //kruskals_algorithm(graph_matrix);
    //dijkstras_algorithm(graph_matrix);
    //graph_traversal(graph_matrix);
    return 0;
}
