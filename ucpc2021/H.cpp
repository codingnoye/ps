#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> ii;

ll N, M, K, S, T;
ll times[20][100011];
vector<vector<ii>> slopes;
vector<vector<ii>> lifts;

void solve() {
    cin>>N>>M>>K>>S>>T;
    slopes.resize(N+1);
    lifts.resize(N+1);
    for (int i=0; i<=K; i++) {
        for (int j=1; j<=N; j++) {
            times[i][j] = -1;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, t; cin>>a>>b>>t;
        // a에서 b로 감
        slopes[b].push_back({a, t});
        lifts[a].push_back({b, 0});
    }
    times[0][S] = 0;
    for (int k=0; k<=K; k++) {
        if (k != 0)
            for (int i=N; i>=1; i--) {
                for (auto lift : lifts[i]) {
                    if (times[k-1][lift.first] == -1) continue;
                    times[k][i] = max(times[k][i], times[k-1][lift.first]);
                }
            }
        for (int i=1; i<=N; i++) {
            for (auto slope : slopes[i]) {
                if (times[k][slope.first] == -1) continue;
                times[k][i] = max(times[k][i], times[k][slope.first] + slope.second);
            }
        }
    }
    ll mx = -1;
    for (int k=0; k<=K; k++) {
        mx = max(mx, times[k][T]);
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}