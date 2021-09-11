#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int N;
int dp[10001][3];
int joomin[10001];
vector<vector<int>> G;

int dfs(int node, int d, int from) {
    if (dp[node][d] != 0) return dp[node][d];
    if (d == 0) {
        int res = joomin[node];
        for (int next: G[node]) {
            if (next == from) continue;
            res += dfs(next, 1, node);
        }
        return dp[node][d] = res;
    } else if (d == 1) {
        // 인접한 경우
        int res = 0;
        for (int next: G[node]) {
            if (next == from) continue;
            // 자손이 우수거나 아닌 경우 둘다 고려
            res += max(dfs(next, 2, node), dfs(next, 0, node));
        }
        return dp[node][d] = res;
    } else { // d == 2
        // 인접한 경우
        int res = 0;
        for (int leasti=0; leasti<G[node].size(); leasti++) {
            int res2 = 0;
            for (int i=0; i<G[node].size(); i++) {
                int next = G[node][i];
                if (next == from) continue;
                if (i == leasti)
                    res2 += dfs(next, 0, node);
                else
                    res2 += max(dfs(next, 2, node), dfs(next, 0, node));
            }
            res = max(res, res2);
        }
        return dp[node][d] = res;
    }
}

void solve() {
    cin>>N;
    G.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin>>joomin[i];
    }
    for (int i = 1; i <= N-1; i++) {
        int a, b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout<<max(dfs(1, 0, -1), dfs(1, 2, -1))<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}