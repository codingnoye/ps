#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll cnt[1001];
int arr[1000001];
int dp[1000001];
void solve() {
    int N, M; cin>>N>>M;
    for (int i = 0; i < N; i++) {
        cin>>arr[i];
        arr[i] %= M;
    }
    dp[0] = 0;
    cnt[0]++;
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i-1] + arr[i-1]) % M;
        cnt[dp[i]]++;
    }
    // for (int i=0; i<=N; i++) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    ll res = 0;
    for (int i = 0; i < M; i++) {
        if (cnt[i] >= 2) {
            res += cnt[i] * (cnt[i] - 1) / 2;
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}