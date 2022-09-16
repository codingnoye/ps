#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

int presum[3003];

int dp[3003];

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> A(N+1);
    for (int i=1; i<=N; i++) cin>>A[i];
    int T, H; cin>>T>>H;

    sort(all(A));

    for (int i=1; i<=N; i++) presum[i] = presum[i-1] + A[i];

    for (int hi=1; hi<=N; hi++) {
        dp[hi] = dp[hi-1] + A[hi] * T;
        for (int lo=hi; lo>=1; lo--) {
            int mid = (lo+hi)/2;
            int low_dists = (A[mid] * (mid - lo) - max(0, presum[mid-1] - presum[lo-1])) * T;
            int high_dists = ((presum[hi] - presum[mid]) - A[mid] * (hi - mid)) * T;

            dp[hi] = min(dp[hi], dp[lo-1] + low_dists + high_dists + H);
        }
    }
    cout<<dp[N]<<endl;
}