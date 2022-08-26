#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

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
    
    int N, M, Q; cin>>N>>M>>Q;
    vector<ll> sz(N, 1);
    UF uf(N);

    vector<pair<int, int>> edges(M);
    for (int i=0; i<M; i++) {
        int u, v; cin>>u>>v; u--; v--;
        edges[i] = {u, v};
    }

    vector<int> cut_edges;
    set<int> cut_edges_s;
    for (int i=0; i<Q; i++) {
        int edge_id; cin>>edge_id; edge_id--;
        cut_edges.push_back(edge_id);
        cut_edges_s.insert(edge_id);
    }

    for (int i=0; i<M; i++) {
        if (cut_edges_s.find(i) != cut_edges_s.end()) continue;
        auto [u, v] = edges[i];
        int pu = uf.f(u);
        int pv = uf.f(v);
        if (pu != pv) {
            sz[min(pu, pv)] += sz[max(pu, pv)];
            sz[max(pu, pv)] = 0;
            uf.u(pu, pv);
        }
    }

    ll ans = 0;
    for (int i=Q-1; i>=0; i--) {
        auto [u, v] = edges[cut_edges[i]];
        int pu = uf.f(u);
        int pv = uf.f(v);
        if (pu != pv) {
            // cout<<"cut "<<u+1<<" "<<v+1<<" "<<sz[pu]<<" "<<sz[pv]<<" "<<(sz[pu] * sz[pv])<<endl;
            ans += sz[pu] * sz[pv];
            sz[min(pu, pv)] += sz[max(pu, pv)];
            sz[max(pu, pv)] = 0;
            uf.u(pu, pv);
        }
    }
    cout<<ans<<endl;
}