#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

int A[753][753];
int DR[753][753];
int DL[753][753];

int main() {
    fastio;
    
    int Y, X; cin>>Y>>X;

    for (int y=1; y<=Y; y++) {
        string tmp; cin>>tmp;
        for (int x=1; x<=X; x++) {
            A[y][x] = tmp.at(x-1) - '0';
        }
    }
    
    // DR
    for (int y=Y; y>=1; y--) {
        for (int x=1; x<=X; x++) {
            if (A[y][x] == 1) {
                DR[y][x] = DR[y+1][x+1] + 1;
            }
        }
    }

    // DL
    for (int y=Y; y>=1; y--) {
        for (int x=1; x<=X; x++) {
            if (A[y][x] == 1) {
                DL[y][x] = DL[y+1][x-1] + 1;
            }
        }
    }

    int res = 0;
    for (int y=1; y<=Y; y++) {
        for (int x=1; x<=X; x++) {
            int s = min(DL[y][x], DR[y][x]);
            while (s>0) {
                if (DR[y+(s-1)][x-(s-1)] >= s && DL[y+(s-1)][x+(s-1)] >= s) {
                    res = max(res, s);
                    break;
                }
                
                s--;
            }
        }
    }
    cout<<res<<endl;
}