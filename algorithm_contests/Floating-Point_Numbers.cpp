#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    double input = 9.205357638345294e18;
    int base = 0, exp = 0, mantissa = 0;
    while(input > 1) {
        input /= 2;
        ++base;
    }
    while(base > 0) {
        base /= 2;
        ++exp;
    }
    cout<<endl<<"num of exp "<<exp<<endl;


    cout<<input<<endl;
    printf("%.18lf\n", input);
    cout<<"base "<<base<<endl;
    int a = input*1000000000;
    cout<<"a is "<<a<<endl;
    int tmp = 0;
    while(a > 0) {
        tmp = a % 2;
        ++mantissa;
        cout<<tmp;
        a /= 2;
    }
    cout<<endl<<"mantissa "<<mantissa<<endl;

    int sum = 0;
    for(int i=9; i>-1; --i){
        cout<<"pow(2,"<<i<<") is "<< pow(2, i)<<endl;
        sum += pow(2, i);
    }
    cout<<" sum  is "<<sum;

    cout<<endl;


    return 0;
}
