#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
const int max_size = 5000;

int is_substr(vector<int> &vec, int vec_begin, int start)
{
    if(start+1 >= max_size-start)
        return 0;
    //    cout<<"start inside is "<<start<<endl;
    //    cout<<"vec begin is "<<vec_begin<<endl;
    for(int i=vec_begin; i<start; ++i) {
        for(int n=1; (start-vec_begin)*n+i<vec.size(); ++n) {
            if(vec[i] != vec[(start-vec_begin)*n+i])
                return 0;
        }
    }
    return 1;
}

int print(vector<int> &vec, int start, int end, int num_of_digits)
{
    //    cout<<"start is "<<start<<endl;
    if(num_of_digits != 0) {
        for(int i=0; i<end; ++i) {
            if(i == start)
                cout<<"(";
            cout<<vec[i];
            if(i >= 49) {
                cout<<"...";
                break;
            }
        }
    }
    return num_of_digits;
}

int is_digital(vector<int> &vec, int start)
{
    int num_of_digits = 0, is_repeat = 0;
    for(int i=start+1; i<vec.size(); ++i) {
        //            cout<<"start is "<<start<<" i Is "<<i<<endl;
        if(vec[start] == vec[i]) {
            //            if(vec.size()%i != 0)
            //                continue;
            is_repeat = is_substr(vec, start, i);
            if(is_repeat != 0) {
                num_of_digits = i - start;
                return print(vec, start, i, num_of_digits);
            }
        }
    }
    return 0;
}
int main()
{
    int a, b;
    while(cin>>a>>b) {
        int num_of_digits=0, origin_a = a;
        vector<int> vec;
        while(a >= b)
            a %= b;
        for(int i=0; i<max_size; ++i) {
            num_of_digits = (double)a/b * 10;
            vec.push_back(num_of_digits);
            a = a * 10 % b;
        }
        vector<int>::iterator it = vec.begin();
        cout<<origin_a<<"/"<<b<<" = "<<origin_a/b<<".";
        num_of_digits = 0;
        for(int i=0; i<vec.size(); ++i) {
            num_of_digits = is_digital(vec, i);
            if(num_of_digits != 0)
                break;
        }
        cout<<")"<<endl;
        cout<<"   "<<num_of_digits<<" = number of digits in repeating cycle"<<endl<<endl;
    }
    return 0;
}
