#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        vector<int> A(N+2);
        for (int i=1; i<=N; i++) cin>>A[i];
        vector<int> psum(N+2);
        for (int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i];

        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        vector<vector<int>> K(N+2, vector<int>(N+2, 0));

        for (int i=1; i<=N; i++) K[i-1][i] = i;

        for (int sz=2; sz<=N; sz++) {
            for (int i=0; i+sz<=N; i++) {
                int j = i+sz;
                dp[i][j] = 987654321;
                for (int k=K[i][j-1]; k<=K[i+1][j]; k++) {
                    int now = dp[i][k] + dp[k][j] + psum[j] - psum[i];
                    if (dp[i][j] > now) {
                        dp[i][j] = now;
                        K[i][j] = k;
                    }
                }
            }
        }
        cout<<dp[0][N]<<endl;
    }
}