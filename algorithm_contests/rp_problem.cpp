#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

/*
 *
 * 当RP变化值a为正，获益值c必定为负，只有你当前的RP值小于等于RP门槛值b的时候，此事件才有可能发生，当此事件发生时，你的RP值将增加|a|，获益值将减少|c|。
 * 反之，当RP变化值a为负，获益值c必定为正，只有你当前的RP值大于等于RP门槛值b的时候，此事件才有可能发生，当此事件发生时，你的RP值将减少|a|，获益值将增加|c|。
一个事件在满足上述RP条件的前提下，未必会发生。
a>0 rp<=b ==>
a<0 rp>=b ==>
*
*/
int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input3.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif

    //freopen ("input.txt", "r", stdin);
    return 0;
}
