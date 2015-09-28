#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct _pane {
    int x;
    int y;
} pane;

bool operator==(struct _pane a, struct _pane b)
{
    if(a.x==b.x && a.y==b.y)
        return 1;
    else
        return 0;
}

bool cmp(struct _pane a, struct _pane b)
{
    if(a.x<b.x && a.y<b.y)
        return 1;
    else
        return 0;
}



int main()
{
    int x, y, count=0;
    vector<struct _pane> vec;
    while(cin>>x>>y) {
        count++;
        struct _pane a;
        a.x = x;
        a.y = y;
        vec.push_back(a);
        if(count%6 == 0) {
            sort(vec.begin(), vec.end(), cmp);
            vector<struct _pane>::iterator it;
            cout<<"start "<<endl;
            for(it=vec.begin(); it!=vec.end(); it++)
                cout<<it->x<<" "<<it->y<<endl;
            cout<<"end "<<endl;
            for(int i=0; i<count; i+=2) {
                if(!(vec[i]==vec[i+1])) {
                    cout<<"IMPOSSIBLE"<<endl;
                    break;
                }
            }
        }
    }
}
