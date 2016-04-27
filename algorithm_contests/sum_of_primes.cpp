#include <cctype>
#include <unistd.h>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
using namespace std;

int main() {
    long long int n = 10e9, sum = 0, k = 0;
    map<int, int> mymap;
    for(int i=2; i<=n; ++i) {
        for(int j=2; j<n; ++j) {
            k = i*j;
            if(k > n)
                break;
            sum += k;
            mymap[k]++;
        }
        sum += i;
    }
    for(auto it : mymap) {
        //        cout<<"it.first "<<it.first<<" ";
        //        cout<<"it.second "<<it.second<<endl;
        if(it.second > 0) {
            sum -= it.first*(it.second+1);
        }
    }
    cout<<"sum is "<<sum<<endl;
    return 0;
}
