#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node {
    int dp = -1;
    set<int> neighbors;
};

vector<Node> nodes;

int visit(int node_id) {
    Node& now = nodes[node_id];
    if (now.dp != -1) return 1 + now.dp;

    now.dp = 0;
    int deg = now.neighbors.size();
    for (int neid: now.neighbors) {
        Node& ne = nodes[neid];
        if (deg < ne.neighbors.size()) {
            now.dp = max(now.dp, visit(neid));
        }
    }
    return 1 + now.dp;
}

int main() {
    fastio;
    
    int N, M; cin>>N>>M;
    nodes = vector<Node>(N);

    ff(m, 0, M) {
        int u, v; cin>>u>>v;
        nodes[u].neighbors.insert(v);
        nodes[v].neighbors.insert(u);
    }

    int mx = 0;

    ff(i, 0, N) {
        mx = max(mx, visit(i));
        // cout<<i<<' '<<visit(i)<<endl;
    }
    cout<<mx<<endl;
}