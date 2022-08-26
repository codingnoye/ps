#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<vector<pair<int, int>>> adj_list;

class LCA {
    vector<int> depths;
    vector<vector<int>> ancestors;
    vector<vector<ll>> costs;
public:
    LCA (adj_list& tree, int root) {
        int N = tree.size();
        ancestors = vector<vector<int>>(N);
        costs = vector<vector<ll>>(N);
        depths = vector<int>(N);
        
        queue<int> q; q.push(root);
        ancestors[root].push_back(root);
        costs[root].push_back(0);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            int depth = depths[now];
            for (int i=1, d=2; d<=depth; d<<=1, i++) {
                ancestors[now].push_back(ancestors[ancestors[now][i-1]][i-1]);
                costs[now].push_back(costs[now][i-1] + costs[ancestors[now][i-1]][i-1]);
            }
            for (auto [child, cost]: tree[now]) {
                if (ancestors[now][0] == child) continue;
                ancestors[child].push_back(now);
                costs[child].push_back(cost);
                depths[child] = depth+1;
                q.push(child);
            }
        }
    }
    int find(int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);
        int dv = depths[v];
        while (depths[u] > dv) {
            int diff = depths[u] - dv;
            int jump = 0, jumpd = 1;
            while (jumpd<<1 <= diff) jumpd<<=1, jump++;
            u = ancestors[u][jump];
        }
        while (u != v) {
            int jump;
            for (jump=1; jump<ancestors[u].size() && ancestors[u][jump]!=ancestors[v][jump]; jump++);
            u = ancestors[u][jump-1];
            v = ancestors[v][jump-1];
        }
        return u;
    }
    ll find_cost(int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);
        int dv = depths[v];
        ll cost = 0;
        while (depths[u] > dv) {
            int diff = depths[u] - dv;
            int jump = 0, jumpd = 1;
            while (jumpd<<1 <= diff) jumpd<<=1, jump++;
            cost += costs[u][jump];
            u = ancestors[u][jump];
        }
        while (u != v) {
            int jump;
            for (jump=1; jump<ancestors[u].size() && ancestors[u][jump]!=ancestors[v][jump]; jump++);
            cost += costs[u][jump-1];
            cost += costs[v][jump-1];
            u = ancestors[u][jump-1];
            v = ancestors[v][jump-1];
        }
        return cost;
    }
    int find_kth_from_u(int u, int v, int k) {
        int lca = find(u, v);
        // path = u -> lca, lca -> v;
        // depth[u] + 1 + depth[v];
        if (k <= depths[u] + 1 - depths[lca]) {
            int i=1;
            while (i<k) {
                int diff = k - i;
                int jump = 0, jumpd = 1;
                while (jumpd<<1 <= diff) jumpd<<=1, jump++;
                u = ancestors[u][jump];
                i += jumpd;
            }
            return u;
        } else {
            int i=depths[u] + 1 + depths[v] - depths[lca] - depths[lca];
            while (i>k) {
                // cout<<i<<" "<<k<<endl;
                int diff = i - k;
                int jump = 0, jumpd = 1;
                while (jumpd<<1 <= diff) jumpd<<=1, jump++;
                v = ancestors[v][jump];
                // cout<<jumpd<<" "<<v<<endl;
                i -= jumpd;
            }
            return v;
        }
    }
};

int main() {
    fastio;
    
    int N; cin>>N;
    adj_list G(N+1);

    for (int i=0; i<N-1; i++) {
        int u, v, w; cin>>u>>v>>w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    LCA lca(G, 1);

    int M; cin>>M;
    for (int i=0; i<M; i++) {
        int c; cin>>c;
        if (c==1) {
            int u, v; cin>>u>>v;
            cout<<lca.find_cost(u, v)<<endl;
        } else {
            int u, v, k; cin>>u>>v>>k;
            cout<<lca.find_kth_from_u(u, v, k)<<endl;
        }
    }
}