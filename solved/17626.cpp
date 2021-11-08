#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    vector<int> zegobs(224);
    for (int i=1; i<224; i++) {
        zegobs[i] = i*i;
    }
    int N; cin>>N;
    vector<int> dp(N+1, 1000000);
    dp[0] = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<224; j++) {
            if (zegobs[j] > i) break;
            dp[i] = min(dp[i], dp[i - zegobs[j]] + 1);
        }
    }
    cout<<dp[N]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}