#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int H[200001];
int W[200001];

int mabs(int x) {
    if (x<0) return -x;
    return x;
}

int dp[200002];
void solve() {
    int N, M; cin>>N>>M;
    cin>>H[0];
    for (int i=1; i<N; i++) {
        cin>>H[i];
    }
    sort(H, H+N);
    for (int i=0; i<M; i++) cin>>W[i];
    sort(W, W+M);

    dp[0] = 0;
    for (int i=2; i<=N; i+=2) {
        dp[i] = dp[i-2] + (H[i-1]-H[i-2]);
    }
    dp[1] = 0;
    for (int i=3; i<=N+2; i+=2) {
        dp[i] = dp[i-2] + (H[i-1]-H[i-2]);
    }
    for (int i=0; i<=N; i++) {
        cout<<dp[i]<<" "<<endl;
    }
    for (int i=0; i<M; i++) {
        int found = lower_bound(H, H+N, W[i]) - H;
        int dist = 0;
        if (found%2==0) {
            dist += W[i] - H[found-1];
            dist += dp[found];
            dist += dp[N] - dp[found];
        } else {
            dist += H[found] - W[i];
            dist += dp[found+1];
            dist += dp[N+2] - dp[found];
        }
        cout<<dist<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}