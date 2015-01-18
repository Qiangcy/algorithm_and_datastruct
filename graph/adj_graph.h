#include <stdio.h>

typedef struct edge_node{
    int adjvex;
    struct edge_node *next;
}Edge_node;

typedef struct vertex_node{
    int data;
    struct edge_node *first_edge;
}Adj_list[10];

type struct adj_graph{
    Adj_list adj_list;
    int num_of_vertexs, num_of_edges;
}Adj_Graph;
