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
using namespace std;
bool cmp(int i, int j) { return i<j; }

// <2 die  8
// ==2 || ==3 alive  8
// >3 die  8
// dead around 3, reborn  no
// N*M
//
// 111
// 101
// 100

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int M, N, rounds;
    cin>>M>>N>>rounds;
    M += 2;
    N += 2;
    vector< vector<int> > cells(M, vector<int>(N));
    vector< vector<int> > states(M, vector<int>(N));
    for(int i=1; i<M-1; i++) {
        for(int j=1; j<N-1; j++) {
            cin>>cells[i][j];
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cout<<cells[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int k=0; k<rounds; ++k) {
        for(int i=1; i<M-1; i++) {
            for(int j=1; j<N-1; j++) {
                int aroundLiveCells = allCells(cells, i, j);
                states[i][j] = aroundLiveCells;
            }
        }

        for(int i=1; i<M-1; i++) {
            for(int j=1; j<N-1; j++) {
                for(;states[i][j]<2;) {
                    cells[i][j] = 0;
                    break;
                }
                for(;states[i][j]==3;) {
                    cells[i][j] = 1;
                    break;
                }
                for(;states[i][j]>3;) {
                    cells[i][j] = 0;
                    break;
                }
            }
        }

        cout<<"after "<<k<<" rounds "<<endl;
        for(int i=1; i<M-1; i++) {
            for(int j=1; j<N-1; j++) {
                cout<<cells[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
