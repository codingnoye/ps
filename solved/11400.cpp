#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

vector<int> cut_vertices(vector<vector<int>>& G) {
    int SZ = sz(G);
    vector<int> res; res.reserve(SZ);
    vector<int> visit_timing(SZ);
    int visit_time = 0;

    function<int (int, bool)> dfs = [&] (int node, bool first) {    
        int now_time = ++visit_time;
        visit_timing[node] = now_time;

        int cnt = 0;
        int min_reachable = now_time;
        for (int ch: G[node]) {
            if (visit_timing[ch] == 0) {
                int child_min = dfs(ch, false);
                if (child_min == now_time) cnt++;
                min_reachable = min(min_reachable, child_min);
            } else {
                min_reachable = min(min_reachable, visit_timing[ch]);
            }
        }
        
        if (!first && cnt>0) res.push_back(node);
        else if (first && cnt>1) res.push_back(node);
        return min_reachable;
    };

    for (int i=1; i<SZ; i++) {
        if (visit_timing[i] == 0)
            dfs(i, true);
    }

    return res;
}

vector<pair<int, int>> cut_bridges(vector<vector<int>>& G) {
    int SZ = sz(G);
    vector<pair<int, int>> res;
    vector<int> visit_timing(SZ);
    int visit_time = 0;

    function<int (int, int)> dfs = [&] (int node, int par) {    
        int now_time = ++visit_time;
        visit_timing[node] = now_time;

        int cnt = 0;
        int min_reachable = now_time;
        for (int ch: G[node]) {
            if (ch == par) continue;
            if (visit_timing[ch] == 0) {
                int child_min = dfs(ch, node);
                if (child_min > now_time)
                    res.push_back({min(node, ch), max(node, ch)});
                min_reachable = min(min_reachable, child_min);
            } else {
                min_reachable = min(min_reachable, visit_timing[ch]);
            }
        }

        return min_reachable;
    };

    for (int i=1; i<SZ; i++) {
        if (visit_timing[i] == 0)
            dfs(i, -1);
    }

    return res;
}

int main() {
    fastio;
    
    int V, E; cin>>V>>E;
    vector<vector<int>> G(V+1);
    for (int i=0; i<E; i++) {
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<pair<int, int>> res = cut_bridges(G);
    sort(all(res));
    
    cout<<sz(res)<<endl;
    for (auto [u, v]: res)
        cout<<u<<' '<<v<<endl;
    
}