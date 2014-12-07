#include <iostream>
#include <string>
using namespace std;
int KMP(string origin_string, string sub_string, int next[]);
void Get_Next(string sub_string, int next[]);
int main()
{
    string origin_string;
    cout<<"input origin string"<<endl;
    cin>>origin_string;
    string sub_string;
    cout<<"input sub string"<<endl;
    cin>>sub_string;
    int next[100];
    for(int i=0; i<10; ++i)
        next[i] = 0;
    Get_Next(sub_string, next);
    for(int i=0; i<10; ++i)
        cout<<next[i]<<' ';
//    cout<<"KMP"<<KMP(origin_string, sub_string, next)<<endl;
}

int KMP(string origin_string, string sub_string, int next[])
{
    int i=0, j=0, record=0;//sub_string[j]
    while (j < sub_string.length()) {
        record = i;
        if (origin_string[i] == sub_string[j]) {
            ++i;
            ++j;
            cout<<"equal: i is "<<i<<endl;
        }
        else {
            j -= next[j];
            cout<<"else: j is "<<j<<endl;
        }
        cout<<"record is "<<record<<endl;
    }
    return record;
}

void Get_Next(string sub_string, int next[])
{
    int head = 0, rear = 1;
    while (rear != sub_string.length()) {
        cout<<"rear is "<<rear<<endl;
        if (sub_string[head] == sub_string[rear]) {
            ++head;
            ++rear;
            next[rear] = rear;
            cout<<"get in: rear is "<<rear<<endl;
        }
        else
            ++rear;
    }
}
