#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int A[258][258];
int DPMIN[258][258];
int DPMAX[258][258];

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        
        for (int y=1; y<=N; y++) {
            for (int x=1; x<=N; x++) {
                cin>>A[y][x];
            }
        }

        int res = 0;
        for (int starty=1; starty<=N; starty++) {
            for (int startx=1; startx<=N; startx++) {
                for (int i=1; i<=N; i++) {
                    DPMIN[i][startx-1] = 999999;
                    DPMAX[i][startx-1] = 0;
                    DPMIN[starty-1][i] = 999999;
                    DPMAX[starty-1][i] = 0;
                }
                for (int y=starty; y<=N; y++) {
                    for (int x=startx; x<=N; x++) {
                        DPMIN[y][x] = min({A[y][x], DPMIN[y-1][x], DPMIN[y][x-1]});
                        DPMAX[y][x] = max({A[y][x], DPMAX[y-1][x], DPMAX[y][x-1]});
                        if (DPMIN[y][x] + (y-starty+1)*(x-startx+1) - 1 == DPMAX[y][x]) {
                            ++res;
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<t<<'\n'<<res<<endl;
    }
}