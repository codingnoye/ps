#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int f[200001][19];

void solve() {
    int M; cin>>M;
    for (int i=1; i<=M; i++) cin>>f[i][0];
    for (int j=1; j<19; j++) {
        for (int i=1; i<=M; i++) {
            f[i][j] = f[f[i][j-1]][j-1];
        }
    }
    // for (int i=1; i<=5; i++) {
    //     for (int j=0; j<5; j++) {
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    int Q; cin>>Q;
    for (int i=0; i<Q; i++) {
        int n, x; cin>>n>>x;
        int e = 0;
        while (n) {
            if (n&1) x = f[x][e];
            n>>=1; e++;
        }
        cout<<x<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}