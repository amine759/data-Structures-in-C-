#include<stdio.h>
#include<stdlib.h>

// indirected graph implementation

typedef struct Adj_node{
    int data ; 
    struct Adj_node *next ;
}Adj_node;

typedef struct Adj_list
{
    Adj_node* head;
}Adj_list;

typedef struct Graph
{
    int nb_vertices ;
    Adj_list *Vertex ;
}Graph;


Adj_node* Create_node(int value);

Adj_node* Create_node(int value){

    struct Adj_node* newNode = (Adj_node*)malloc(sizeof(Adj_node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(unsigned long nb_vertices){
    struct Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nb_vertices = nb_vertices;
    graph->Vertex = (Adj_list*)malloc(nb_vertices*sizeof(nb_vertices));
    int i;
    for (i = 0; i < nb_vertices; ++i)
        graph->Vertex[i].head = NULL;
 
    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    struct Adj_node* temp = NULL ; 
    struct Adj_node* new_node = Create_node(dest);

    if(graph->Vertex[src].head == NULL){
        new_node->next = graph->Vertex[src].head ; 
        graph->Vertex[src].head = new_node; 
    } 
    else {
        temp = graph->Vertex[src].head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new_node ;
    }
    new_node = Create_node(src);

    if(graph->Vertex[dest].head == NULL){
        new_node->next = graph->Vertex[dest].head ; 
        graph->Vertex[dest].head = new_node; 
    } 
    else {
        temp = graph->Vertex[dest].head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new_node ;
    }
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->nb_vertices; ++v) {
        struct Adj_node* HEAD = graph->Vertex[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (HEAD) {
            printf("-> %d", HEAD->data);
            HEAD = HEAD->next;
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    unsigned long nb_Vertices = 5;
    Graph* graph = createGraph(nb_Vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above
    // graph
    printGraph(graph);    

    free(graph);
    return 0;
}
