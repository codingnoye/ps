#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int dp[3][100001];

int getdp(int i, int j) {
    ull res = 0;
    for (int k=0; k<3; k++) {
        if (k==j) continue;
        if (i-j-1 <= 0) continue;
        res += dp[k][i-j-1];
    }
    return res % 1000000009;
}
void solve() {
    int T; cin>>T;
    dp[0][1] = 1;
    dp[0][3] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    for (int i=4; i<=100001; i++) {
        for (int j=0; j<3; j++) {
            dp[j][i] = getdp(i, j);
        }
    }
    while (T--) {
        int N; cin>>N;
        cout<<(((ull)dp[0][N]+(ull)dp[1][N]+(ull)dp[2][N])%1000000009)<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}