#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<vector<int>> adj_list;

// undirected tree -> rooted tree
adj_list make_rooted_tree(adj_list& G, int root) {
    adj_list rooted_graph(G.size());
    function<void(int, int)> dfs = [&] (int now, int from) {
        for (int near: G[now]) {
            if (near == from) continue;
            rooted_graph[now].push_back(near);
            dfs(near, now);
        }
    };
    dfs(root, -1);
    return rooted_graph;
}

class LCA {
    adj_list tree;
    vector<int> depths;
    vector<vector<int>> ancestors;
public:
    LCA (adj_list& tr, int root) {
        tree = tr;
        int N = tree.size();
        ancestors = vector<vector<int>>(N);
        depths = vector<int>(N);

        function<void(int, int, int)> dfs = [&] (int now, int par, int depth) {
            depths[now] = depth;
            for (int i=0, d=1; d<=depth; d<<=1, i++) {
                if (d==1) {
                    ancestors[now].push_back(par);
                } else {
                    ancestors[now].push_back(ancestors[ancestors[now][i-1]][i-1]);
                }
            }
            for (int child: tree[now]) {
                dfs(child, now, depth+1);
            }
        };
        dfs(root, root, 0);
    }
    int find(int u, int v) {
        if (depths[u] < depths[v]) swap(u, v);
        int dv = depths[v];
        while (depths[u] > dv) {
            int diff = dv - depths[u];
            int jump = 0, jumpd = 1;
            while (jumpd<<1 <= diff) jumpd<<=1, jump++;
            u = ancestors[u][jump];
        }
        while (u != v) {
            u = ancestors[u][0];
            v = ancestors[v][0];
        }
        return u;
    }
};

int main() {
    fastio;
    
    int N; cin>>N;
    adj_list G(N+1);
    for (int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    adj_list rooted_tree = make_rooted_tree(G, 1);
    LCA lca(rooted_tree, 1);
    
    int M; cin>>M;
    while (M--) {
        int u, v; cin>>u>>v;
        cout<<lca.find(u, v)<<endl;
    }
}