#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int INF = 987654321;
const int MAX = 401;

vector<vector<int>> G(MAX);
int flowing[MAX][MAX];
int cap[MAX][MAX];
int from[MAX];

void solve() {
    int N, P; cin>>N>>P;
    for (int p=0; p<P; p++) {
        int a, b; cin>>a>>b;
        cap[a][b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int S = 1, T = 2;
    int total_flow = 0;
    while (1) {
        for (int i=0; i<=N; i++) {
            from[i] = -1;
        }
        queue<int> q;
        q.push(S);

        while (!q.empty()) {
            int now = q.front(); q.pop();
            
            for (auto next: G[now]) {
                if (from[next] != -1) continue;

                if (cap[now][next] - flowing[now][next] > 0) {
                    q.push(next);
                    from[next] = now;

                    if (next == T) break;
                } 
            }
        }

        if (from[T] == -1) break;

        int flow = INF;
        for (int i=T; i!=S; i=from[i]) {
            flow = min(flow, cap[from[i]][i] - flowing[from[i]][i]);
        }
        for (int i=T; i!=S; i=from[i]) {
            flowing[from[i]][i] += flow;
            flowing[i][from[i]] -= flow;
        }
        total_flow += flow;
    }
    cout<<total_flow<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}