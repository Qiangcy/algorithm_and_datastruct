#include "graph.h"
int main()
{
    Graph<int> *g = new Graph<int>;
    g->Init_Graph(g);
    g->Output_Graph(g);
    cout<<"BFS!"<<endl;
    g->BFS(g);
    char c;
    cin>>c;
    cout<<"DFS!"<<endl;
    g->DFS(g);
}

