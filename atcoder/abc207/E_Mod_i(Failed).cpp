#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

const ull MOD = 1000000007LL;
ull acc[3002];
int N;
ull A[3002];
ull dp[3002][3002];
ull recc(int i, int x) {
    if (dp[i][x] != 0) return dp[i][x]-1;
    if (i==N) {
        return 1;
    }
    ull res = 0;
    for (int j=i+1; j<=N; j++) {
        if ((acc[j] - acc[i]) % x != 0) continue;
        res += recc(j, x+1);
    }
    dp[i][x] = res+1;
    return res;
}

void solve() {
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i];
    }
    for (int i=1; i<=N; i++) {
        acc[i] = acc[i-1] + A[i-1];
    }
    cout<<(recc(0, 1)%MOD)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}