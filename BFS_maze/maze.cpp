#include "maze_class.h"
using namespace std;

int main()
{
    int row, column;
    cout<<"input row"<<endl;
    cin>>row;
    cout<<"input column"<<endl;
    cin>>column;
    Maze *maze = new Maze(row, column);
    maze->input_maze(maze);
    maze->go_to_maze(maze);
    maze->print_maze(maze);
}
