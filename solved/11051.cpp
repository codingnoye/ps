#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int dp[1003][1003];

void solve() {
    int N, K; cin>>N>>K;
    dp[0][1] = 1;
    for (int i=1; i<1003; i++) {
        for (int j=1; j<=i+1; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
        }
    }
    cout<<dp[N][K+1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}