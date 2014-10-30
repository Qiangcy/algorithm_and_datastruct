#include <iostream>
#include <vector>
#include "../my_includes/MyStack.h"
using namespace std;

typedef struct _point {
    int x, y;
} point;

class Maze {
    public:
        int row,column;
        //       static vector< vector<int> > data;
        int data[100][100];
        point current_point, pre_point;
        MyStack <point> pre_stack;

        Maze(int input_row=10, int input_column=10) {
            this->row = input_row;
            this->column = input_column;
            this->current_point.x=0, this->current_point.y=0;
            //            this->data(13, vector<int>(column));
            for (int i=0; i<row; ++i)
                for (int j=0; j<column; ++j)
                    this->data[i][j] = 0;
            cout<<"contruct function"<<endl;
        }

        void input_maze(Maze* &M);
        void print_maze(Maze* &M);
        void go_to_maze(Maze* &M);
        void visit_maze(Maze* &M, int x, int y);
        void translate_path(Maze* &M, int x, int y);
};

void Maze::input_maze(Maze* &M)
{
    for (int i=0; i<M->row; ++i) {
        for (int j=0; j<M->column; ++j) {
            int temp = 0;
            cin>>temp;
            if (temp == 0)
                M->data[i][j] = 0;
            else
                M->data[i][j] = 1;
        }
    }
}

void Maze::go_to_maze(Maze* &M)
{
    int x = 0, y = 0;
    visit_maze(M, x, y);//down
    //M->pre_stack.pushme(M->current_point);

    cout<<"M->row is "<<M->row<<endl;
    cout<<"M->col is "<<M->column<<endl;
    char c;
    scanf("%c", &c);
    while (! M->pre_stack.empty()) {
        //  while (x+1 != M->row && y+1 != M->column)
        M->current_point = M->pre_stack.pop();
        cout<<"####TOP: "<<M->pre_stack.Top()<<"####"<<endl;
        cout<<"pop: last point: ("<<M->pre_point.x<<", "<<M->pre_point.y<<')'<<endl;
        x = M->current_point.x, y = M->current_point.y;
        print_maze(M);
        cout<<"now(x,y) : ("<<x<<", "<<y<<')'<<endl;
        char c;
        scanf("%c", &c);

        if (M->data[x][y+1] == 1 && y+1 <= M->column) {//right
            cout<<"right"<<endl;
            char c;
            scanf("%c", &c);
        M->pre_point.x=M->current_point.x, M->pre_point.y=M->current_point.x;
            M->current_point.y = y = y + 1;
            visit_maze(M, x, y);
            cout<<"after go : ("<<x<<", "<<y<<')'<<endl;
            //continue;
        }
        if (M->data[x+1][y] == 1 && x+1 <= M->row) {//down
            cout<<"down"<<endl;
            char c;
            scanf("%c", &c);
        M->pre_point.x=M->current_point.x, M->pre_point.y=M->current_point.x;
            M->current_point.x = x  = x + 1;
            visit_maze(M, x, y);
            cout<<"after go : ("<<x<<", "<<y<<')'<<endl;
         //   continue;
        }
        if (M->data[x-1][y] == 1 && x-1 >= 0) {//up
            cout<<"up"<<endl;
            char c;
            scanf("%c", &c);
        M->pre_point.x=M->current_point.x, M->pre_point.y=M->current_point.x;
            M->current_point.x = x = x - 1;
            visit_maze(M, x, y);
            cout<<"after go : ("<<x<<", "<<y<<')'<<endl;
        //    continue;
        }
        if (M->data[x][y-1] == 1 && y-1 >= 0) {//left
            cout<<"left"<<endl;
            char c;
            scanf("%c", &c);
        M->pre_point.x=M->current_point.x, M->pre_point.y=M->current_point.x;
            M->current_point.y  = y = y - 1;
            visit_maze(M, x, y);
            cout<<"after go : ("<<x<<", "<<y<<')'<<endl;
           // continue;
        }

        if (x+1 == M->row && y+1 == M->column) {
            //            M->data[M->pre_point.x][M->pre_point.y] = 3;
            cout<<"break!!!!!!!!!!!!!"<<endl;
            break;
        }
    }
    if (x+1 != M->row && y+1 != M->column) {
        cout<<"last point: ("<<M->pre_point.x<<", "<<M->pre_point.y<<')'<<endl;
        cout<<"now(x,y) : ("<<M->current_point.x<<", "<<M->current_point.y<<')'<<endl;
        cout<<"no path to the end!"<<endl;
        M->data[M->current_point.x][M->current_point.y] = 2;
    } else {
        M->data[M->current_point.x][M->current_point.y] = 3;
    }

    //    while (! M->pre_stack.empty()) {
    //        M->pre_point = M->pre_stack.pop();
    //        cout<<"path : ("<<M->pre_point.x<<", "<<M->pre_point.y<<')'<<endl;
    //        M->data[M->pre_point.x][M->pre_point.y] = 3;
    //    }
    scanf("%c", &c);
}

void Maze::visit_maze(Maze* &M, int x, int y)
{
    M->pre_stack.pushme(M->current_point);
    M->data[x][y] = 2;
}

void Maze::print_maze(Maze* &M)
{
    cout<<"*******************"<<endl;
    for (int i=0; i<M->row; ++i) {
        for (int j=0; j<M->column; ++j) {
            if (M->data[i][j] == 0)
                cout<<'0';
            else if (M->data[i][j] == 1)
                cout<<'1';
            else if (M->data[i][j] == 2)
                cout<<'x';
            else
                cout<<'3';
               // translate_path(M, i, j);
        }
        cout<<endl;
    }
    cout<<"*******************"<<endl;
}

void Maze::translate_path(Maze* &M, int x, int y)
{
    if (M->data[x+1][y] == 3 )
        cout<<'d';//down_arrow
    else if (M->data[x][y+1] == 3)
        cout<<'r';//right_arrow
    else if (M->data[x-1][y] == 3)
        cout<<'u';//up_arrow
    else if (M->data[x][y-1] == 3)
        cout<<'L';//left_arrow
    else
        cout<<'+';
}
