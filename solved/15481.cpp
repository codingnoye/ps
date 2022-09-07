#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<vector<pair<int, int>>> adj_list; // dest, w

class LCA {
    vector<int> depths;
    vector<vector<int>> ancestors;
    vector<vector<int>> max_w;
public:
    LCA (adj_list& tree, int root) {
        int N = tree.size();
        ancestors = vector<vector<int>>(N);
        depths = vector<int>(N);
        max_w = vector<vector<int>>(N);
        
        queue<int> q; q.push(root);
        ancestors[root].push_back(root);
        max_w[root].push_back(0);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            int depth = depths[now];
            for (int i=1, d=2; d<=depth; d<<=1, i++) {
                max_w[now].push_back(max(max_w[now][i-1], max_w[ancestors[now][i-1]][i-1]));
                ancestors[now].push_back(ancestors[ancestors[now][i-1]][i-1]);
            }
            for (auto [child, w]: tree[now]) {
                if (ancestors[now][0] == child) continue;
                ancestors[child].push_back(now);
                max_w[child].push_back(w);
                depths[child] = depth+1;
                q.push(child);
            }
        }
    }
    ll find(int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);
        int dv = depths[v];
        int ans = 0;
        while (depths[u] > dv) {
            int diff = depths[u] - dv;
            int jump = 0, jumpd = 1;
            while (jumpd<<1 <= diff) jumpd<<=1, jump++;
            ans = max(ans, max_w[u][jump]);
            u = ancestors[u][jump];
        }
        while (u != v) {
            int jump;
            for (jump=1; jump<ancestors[u].size() && ancestors[u][jump]!=ancestors[v][jump]; jump++);
            ans = max(ans, max_w[u][jump-1]);
            ans = max(ans, max_w[v][jump-1]);
            u = ancestors[u][jump-1];
            v = ancestors[v][jump-1];
        }
        return ans;
    }
};

class UF {
public:
    vector<int> parent;
    UF (int n) {
        parent = vector<int>(n);
        for (int i=0; i<n; i++) parent[i] = i;
    }
    int f(int x) {
        int px = parent[x];
        if (px == x) return x;
        return parent[x] = f(px);
    }
    bool u(int x, int y) {
        int px = f(x);
        int py = f(y);
        if (px == py) return false;
        if (px < py) swap(px, py);
        parent[px] = py;
        return true;
    }  
};

int main() {
    fastio;
    
    int N, M; cin>>N>>M;
    
    UF uf(N+1);
    adj_list G(N+1);

    vector<pair<int, pair<int, int>>> edges(M);
    for (int i=0; i<M; i++) {
        int u, v, w; cin>>u>>v>>w;
        edges[i] = {w, {u, v}};
    }

    vector<pair<int, pair<int, int>>> edges_sort(edges);
    sort(edges_sort.begin(), edges_sort.end());

    ll total = 0;
    for (auto& [w, uv]: edges_sort) {
        auto& [u, v] = uv;
        if (uf.u(u, v)) {
            G[u].push_back({v, w});
            G[v].push_back({u, w});
            total += w;
        }
    }

    LCA lca(G, 1);

    for (auto& [w, uv]: edges) {
        auto& [u, v] = uv;
        cout<<(total - lca.find(u, v) + w)<<endl;
    }
}