#include <iostream>
#include <string>
using namespace std;
int KMP(string origin_string, string sub_string);
int main()
{
    string origin_string;
    cout<<"input origin string"<<endl;
    cin>>origin_string;
    string sub_string;
    cout<<"input sub string"<<endl;
    cin>>sub_string;
}

int KMP(string origin_string, string sub_string)
{
    for (int i=0; origin_string[i]; ++i)
    {
        if (origin_string[i] == sub_string[i])
            ++i;
        else
    }
}
