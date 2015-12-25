#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int map[9][9];
void display(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(int c){
    int x,y,i,j,dx,dy;
    x=c/9;
    y=c%9;
    for(i=0;i<9;i++){
        if(map[i][y]==map[x][y]&&x!=i)
            return false;
    }
    for(j=0;j<9;j++){
        if(map[x][j]==map[x][y]&&y!=j)
            return false;
    }
    dx=x/3*3;
    dy=y/3*3;
    for(i=dx;i<dx+3;i++){
        for(j=dy;j<dy+3;j++){
            if(map[i][j]==map[x][y]&&i!=x&&j!=y)
                return false;
        }
    }
    return true;
}

void backtrack(int n) {
    int x,y;
    if(n==81){
        //if(check(80))
        display();
        cout<<endl;
        return ;
    }
    x=n/9;
    y=n%9;
    if(map[x][y]==0){
        for(int k=1;k<=9;k++){
            if(map[x][y]==0)
                map[x][y]=k;
            if(check(n)){
                backtrack(n+1);
            }
            map[x][y]=0;         //请注意此处应当清零，如果不清零下一次就没有办法触发！！！
        }
        return;
    }
    else{
        backtrack(n+1);
    }
}

int main(){
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int temp[9];
    for(int i=0;i<9;i++) {
        cin>>temp[i];
    }
    for(int i=0;i<9;i++) {
        for(int j=8; j>-1; j--) {
            map[i][j] = temp[i]%10;
            temp[i] /= 10;
        }
    }
    //display();
    backtrack(0);
    return 0;
}
