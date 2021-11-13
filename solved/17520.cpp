#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[3][100001];

void solve() {
    int N; cin>>N;
    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[2][1] = 1;
    for (int i=2; i<=100000; i++) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = dp[0][i-1] + dp[2][i-1];
        dp[1][i] %= 16769023;
        dp[2][i] = dp[1][i-1];
    }
    cout<<(dp[0][N] + dp[1][N] + dp[2][N])%16769023<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}