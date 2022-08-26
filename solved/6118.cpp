#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, M; cin>>N>>M;
    vector<vector<int>> G(N);
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int lastd = -1, lastc = 0, lastv = -1;
    pq.push({0, 0});

    vector<bool> visited(N);
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (visited[v]) continue;

        visited[v] = true;
        if (lastd == d) {
            lastc++;
            lastv = min(lastv, v);
        } else if (lastd < d) {
            lastd = d;
            lastc = 1;
            lastv = v;
        } else {
            continue;
        }

        for (int n: G[v]) pq.push({d+1, n});
    }
    cout<<lastv+1<<' '<<lastd<<' '<<lastc<<endl;
}