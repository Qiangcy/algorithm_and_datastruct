#include <iostream>
#include <vector>
#include "../my_includes/MyQueue.h"
#include "../my_includes/MyStack.h"
using namespace std;
template <typename Type>
class Graph {
    public:
        int num_of_vertexs;
        vector<Type> vertexs;
        vector< vector<int> > edeges;
        // Graph() {
        // }
        void Init_Graph(Graph* &G);
        void Output_Graph(Graph* &G);
        void DFS(Graph* &G);
        void BFS(Graph* &G);
};

    template <typename Type>
void Graph<Type>::Init_Graph(Graph* &G)
{
    cout<<"input num_of_vertexs"<<endl;
    Type element;
    int edege;
    cin>>G->num_of_vertexs;
    cout<<"input vertexs"<<endl;
    for(int i=0; i<G->num_of_vertexs; ++i) {
        cin>>element;
        G->vertexs.push_back(element);
    }
    cout<<"input edeges"<<endl;
    for(int i=0; i<G->num_of_vertexs; ++i) {
        vector<int> temp;
        for(int j=0; j<G->num_of_vertexs; ++j) {
            cin>>edege;
            temp.push_back(edege);
        }
        G->edeges.push_back(temp);
    }
}

    template <typename Type>
void Graph<Type>::Output_Graph(Graph* &G)
{
    for(int i=0; i<G->num_of_vertexs; ++i) {
        cout<<"vertexs "<<G->vertexs[i]<<' ';
    }
    cout<<endl<<"edeges"<<endl;
    for(int i=0; i<G->num_of_vertexs; ++i) {
        for(int j=0; j<G->num_of_vertexs; ++j) {
            cout<<G->edeges[i][j]<<' ';
        }
        cout<<endl;
    }
}

    template <typename Type>
void Graph<Type>::DFS(Graph* &G)
{
    vector<bool> visted;
    for(int i=0; i<G->num_of_vertexs; ++i)
        visted.push_back(0);
    MyStack<Type> stack;
    int i = 0, j = 0;
    Type temp;
    stack.pushme(G->vertexs[i]);
    while(!stack.empty()) {
        temp = stack.pop();
        cout<<temp<<"  ";
        for(i=0;i<G->num_of_vertexs; ++i) {
            for(j=0;j<G->num_of_vertexs; ++j) {
                if(! visted[j]) {
                    if(G->edeges[i][j] > 0)
                        stack.pushme(G->vertexs[j]);
                    }
                    cout<<"visit vertex:"<<G->vertexs[j]<<endl<<"visit edege"<<G->edeges[i][j];
                    visted[j] = 1;
                }
            }
        }
    cout<<"!finished!"<<endl;
}

    template <typename Type>
void Graph<Type>::BFS(Graph* &G)
{
    vector<bool> visted;
    for(int i=0; i<G->num_of_vertexs; ++i)
        visted.push_back(0);
    MyQueue<Type> queue;
    int i = 0, j = 0;
    Type temp;
    //queue.output_information();
    queue.pushme(G->vertexs[i]);
    while(!queue.empty()) {
        queue.output_information();
        temp = queue.pop();
        cout<<temp<<"  ";
        for(i=0;i<G->num_of_vertexs; ++i) {
            for(j=0;j<G->num_of_vertexs; ++j) {
                if(! visted[j]) {
                    if(G->edeges[i][j] > 0) {
                        if(! queue.pushme(G->vertexs[j])) {
                            cout<<"push fail :break"<<endl;
                            break;
                        }
                    }
                    cout<<"visit vertex:"<<G->vertexs[j]<<endl<<"visit edege"<<G->edeges[i][j];
                    visted[j] = 1;
                }
            }
        }
    }
    cout<<"!finished!"<<endl;
}
