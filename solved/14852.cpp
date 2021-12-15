#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll dp[1000011][3];
// 0 = 둘다있음
// 1 = 위만있음
// 2 = 아래만있음
const int MOD = 1000000007;
void solve() {
    dp[0][0] = 1;
    for (int i=0; i<1000001; i++) {
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i+1][0] += dp[i][0]*2;
        dp[i+1][1] += dp[i][0];
        dp[i+1][2] += dp[i][0];
        dp[i+2][0] += dp[i][0];

        dp[i+1][0] += dp[i][1];
        dp[i+1][2] += dp[i][1];

        dp[i+1][0] += dp[i][2];
        dp[i+1][1] += dp[i][2];
    }
    int N; cin>>N;
    cout<<dp[N][0]%MOD<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}