#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<vector<int>> adj_list;

class LCA {
public:
    vector<int> depths;
    vector<vector<int>> ancestors;
    LCA (adj_list& tree, int root) {
        int N = tree.size();
        ancestors = vector<vector<int>>(N);
        depths = vector<int>(N);
        
        queue<int> q; q.push(root);
        ancestors[root].push_back(root);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            int depth = depths[now];
            for (int i=1, d=2; d<=depth; d<<=1, i++) {
                ancestors[now].push_back(ancestors[ancestors[now][i-1]][i-1]);
            }
            for (int child: tree[now]) {
                if (ancestors[now][0] == child) continue;
                ancestors[child].push_back(now);
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

    LCA lca(G, 1);

    int M; cin>>M;
    while (M--) {
        int r, u, v; cin>>r>>u>>v;
        int l1 = lca.find(u, v);
        int l2 = lca.find(r, u);
        int l3 = lca.find(r, v);
        vector<int> la = {l1, l2, l3};

        int limax = -1;
        int ldmax = -1;
        for (int li: la) {
            if (lca.depths[li] > ldmax) {
                limax = li;
                ldmax = lca.depths[li];
            }
        }
        cout<<limax<<endl;
    }
}