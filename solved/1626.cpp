#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<vector<pair<int, int>>> adj_list; // dest, w

ll touched = 0;
class LCA {
    vector<int> depths;
    vector<vector<int>> ancestors;
    vector<vector<int>> max_w;
    vector<vector<int>> max_w2;
public:
    LCA (adj_list& tree, int root) {
        int N = tree.size();
        ancestors = vector<vector<int>>(N);
        depths = vector<int>(N);
        max_w = vector<vector<int>>(N);
        max_w2 = vector<vector<int>>(N);
        
        queue<int> q; q.push(root);
        ancestors[root].push_back(root);
        max_w[root].push_back(0);
        max_w2[root].push_back(0);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            touched++;
            int depth = depths[now];
            for (int i=1, d=2; d<=depth; d<<=1, i++) {
                vector<ll> candidates = {max_w[now][i-1], max_w2[now][i-1], max_w[ancestors[now][i-1]][i-1], max_w2[ancestors[now][i-1]][i-1]};
                sort(candidates.begin(), candidates.end());
                ll mw = candidates[3];
                ll mw2 = candidates[2];
                for (int i=1; i>=0 && mw == mw2; i--) mw2 = candidates[i];

                max_w[now].push_back(mw);
                max_w2[now].push_back(mw2);
                ancestors[now].push_back(ancestors[ancestors[now][i-1]][i-1]);
            }
            for (auto [child, w]: tree[now]) {
                if (ancestors[now][0] == child) continue;
                ancestors[child].push_back(now);
                max_w[child].push_back(w);
                max_w2[child].push_back(w);
                depths[child] = depth+1;
                q.push(child);
            }
        }
    }
    pair<ll, ll> find(int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);
        int dv = depths[v];
        ll ans = -100000000000;
        ll ans2 = -100000000000;
        while (depths[u] > dv) {
            int diff = depths[u] - dv;
            int jump = 0, jumpd = 1;
            while (jumpd<<1 <= diff) jumpd<<=1, jump++;
            vector<ll> candidates = {ans, ans2, max_w[u][jump], max_w2[u][jump]};
            sort(candidates.begin(), candidates.end());
            ans = candidates[3];
            ans2 = candidates[2];
            for (int i=1; i>=0 && ans == ans2; i--) ans2 = candidates[i];
            u = ancestors[u][jump];
        }
        while (u != v) {
            int jump;
            for (jump=1; jump<ancestors[u].size() && ancestors[u][jump]!=ancestors[v][jump]; jump++);
            vector<ll> candidates = {ans, ans2, max_w[u][jump-1], max_w2[u][jump-1], max_w[v][jump-1], max_w2[v][jump-1]};
            sort(candidates.begin(), candidates.end());
            ans = candidates[5];
            ans2 = candidates[4];
            for (int i=3; i>=0 && ans == ans2; i--) ans2 = candidates[i];
            u = ancestors[u][jump-1];
            v = ancestors[v][jump-1];
        }
        return {ans, ans2};
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
    if (touched < N) {
        cout<<"-1"<<endl;
        return 0;
    }

    ll ans = 99999999999;
    for (auto& [w, uv]: edges) {
        auto& [u, v] = uv;
        if (uf.f(u) != uf.f(v)) {
            cout<<"-1"<<endl;
            return 0;
        }
        auto [mx, mx2] = lca.find(u, v);
        // cout<<u<<" "<<v<<" "<<mx<<" "<<mx2<<endl;
        ll now = total - mx + w;
        if (now != total && mx != -100000000000) ans = min(ans, now);
        now = total - mx2 + w;
        if (now != total && mx != -100000000000) ans = min(ans, now);
    }
    if (ans == 99999999999) ans = -1;
    cout<<ans<<endl;
}