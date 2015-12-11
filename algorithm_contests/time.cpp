#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main(void)
{
    int sum = 0;
    int res  = 0;
    for(int i = 0; i< 1000; ++i)
    {
        for(int j = 0; j< 1000; ++j)
        {
            vector< int> ca;
            int flag = 1;
            sum = i*j;
            if(sum/1000 > 0 && sum/1000<10) {
                int tmp = i, sm = 0, bm=0;
                while(tmp > 0) {
                    sm += tmp % 10;
                    ca.push_back(tmp%10);
                    tmp /= 10;
                }
                tmp = j;
                vector<int>::iterator it;
                while(tmp > 0) {
                    sm += tmp % 10;
                    it = find (ca.begin(), ca.end(), tmp%10);
                    if (it != ca.end()) {
                        flag = 0;//found
                    } else {
                        ca.push_back(tmp%10);
                    }
                    tmp /= 10;
                }
                tmp = sum;
                while(tmp > 0) {
                    bm += tmp % 10;
                    it = find (ca.begin(), ca.end(), tmp%10);
                    if (it != ca.end()) {
                        //   std::cout << "Element found in myvector: " << *it << '\n';
                    } else {
                        flag = 0;
                        // ca.push_back(tmp%10);
                    }
                    tmp /= 10;
                }
                if(bm == sm && sm!=0 && flag == 1) {
                    //                    for(it=ca.begin(); it!=ca.end(); ++it)
                    //                        cout<<*it<< " ";
                    //                    cout<<endl;
                    if(i/1000>0)
                        ;
                    else if(j/1000>0)
                        ;
                    else if(i/100>0 && j/10>0)
                        ;
                    else if(j/100>0 && i/10>0)
                        ;
                    else {
                        cout<<i<<" * "<<j<<"="<<sum<<endl;
                        ++res;
                    }
                }
            }
        }
    }
    cout<<"res  : "<<res<<endl;
}
