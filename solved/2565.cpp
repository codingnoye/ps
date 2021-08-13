#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int N; cin>>N;
    vector<pii> arr(N);
    vector<int> dp(N, 1);
    for(int i=0;i<N;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(), arr.end());
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (arr[i].second < arr[j].second) {
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }
    int mx = 0;
    for (int i=0; i<N; i++) {
        mx = max(mx, dp[i]);
    }
    cout<<(N-mx)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}