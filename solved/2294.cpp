#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int coin[101];
int dp[10001] = {0};
const int MAX = 1000000001;

void solve() {
    int N, K; cin>>N>>K;
    for (int i=0; i<N; i++) {
        cin>>coin[i];
    }
    for (int i=1; i<=K; i++) {
        dp[i] = MAX;
        for (int j=0; j<N; j++) {
            if (i >= coin[j]) {
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }
    if (dp[K] == MAX) cout<<-1<<endl;
    else cout<<dp[K]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}