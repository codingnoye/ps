#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = 987654321;
int dp[502][502];
void solve() {
    int N; cin>>N;
    vector<int> vals(N+1);
    for (int i=0; i<N; i++) {
        cin>>vals[i];
        cin>>vals[i+1];
    }
    for (int i=0; i<N; i++) {
        dp[1][i] = 0;
    }
    // dp[size][start]
    for (int i=2; i<=N; i++) {
        for (int j=0; j<N+1; j++) {
            // j에서 시작해서 i칸
            dp[i][j] = MAX;
            for (int k=1; k<i; k++) {
                int nowcnt = vals[j] * vals[j+k] * vals[j+i] + dp[k][j] + dp[i-k][j+k];
                dp[i][j] = min(dp[i][j], nowcnt);
            }
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }
    cout<<dp[N][0]<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}