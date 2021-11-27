#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef pair<int, int> pii;
typedef vector<vector<pii>> G; // 가중치 인접 리스트, graph[n] = n 노드의 인접 리스트, <노드, 거리>
const int INF = 987654321;

// 0 ~ N-1 권장, 0 ~ N으로 해서 0 버리고 써도 됨
vector<int> get_dist(G& graph, int s) {
    int N = graph.size();
    vector<int> dist(N);
    vector<int> from(N);
    vector<bool> visited(N);
    for (int i=0; i<N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [nowd, now] = pq.top(); pq.pop();
        if (visited[now]) continue;
        for (auto [near, cost]: graph[now]) {
            if (visited[near]) continue;
            if (dist[near] > nowd + cost) {
                dist[near] = nowd + cost;
                from[near] = cost;
            }
            pq.push({dist[near], near});
        }
        visited[now] = true;
    }
    return dist;
}

void solve() {
    int N, M; cin>>N>>M;
    G g(N+1);
    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    cout<<get_dist(g, 1)[N]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}