/* 任意语 实现程序。 给定 个只有数字的字符串,打印出所有它加上 些点后可能形成的合法的ip(任意顺序)。 */
/* 样例输 : */
/* “2502501135” */
/* 样例输出: */
/* 250.250.11.35
 * 250.250.1.135
 * 250.250.113.5
 * */
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>
#include <arpa/inet.h>
using namespace std;

bool isValidIpAddress(const char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    string numbers;
    cin>>numbers;
    int n = numbers.length();
    for(int i=1; i<n; ++i) {
        if(numbers[i] == '0')
            continue;
        numbers.insert(i, ".");
        for(int j=i+2; j<n+1; ++j) {
            if(numbers[j] == '0')
                continue;
            numbers.insert(j, ".");
            for(int k=j+2; k<n+2; ++k) {
                if(numbers[k] == '0')
                    continue;
                numbers.insert(k, ".");
                /* cout<<numbers<<endl; */
                if(isValidIpAddress(numbers.c_str()))
                    cout<<numbers<<endl;
                numbers.erase(k, 1);
            }
            numbers.erase(j, 1);
        }
        numbers.erase(i, 1);
    }

    return 0;
}
