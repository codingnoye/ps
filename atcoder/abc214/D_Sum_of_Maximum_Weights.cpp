#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

struct hedge {
    int v;
    int w;
};

struct hedge_d {
    int v;
    int w;
    int d;
};

struct edge {
    int u; // now
    int v; // parent
    int w; // w
};

vector<hedge> G[100002];

hedge_d tree[100002];
bool visited[100002];

int if_same_get_g (int u, int v) {
    if (tree[u].d >= tree[v].d) {
        swap(u, v);
    }
    int g = 0;
    while (tree[u].d < tree[v].d-1) {
        g = max(g, tree[v].w);
        v = tree[v].v;
    }

    if (u != tree[v].v) {
        return -1;
    } else {
        g = max(g, tree[v].w);
        //cout<<u<<' '<<v<<" same "<<g<<endl;
        return g;
    }
}

int gg[100002];

void make_tree(int u, int nowMax, int d=0) {
    visited[u] = true;
    for (auto child: G[u]) {
        if (visited[child.v]) continue;
        tree[child.v].v = u;
        tree[child.v].w = child.w;
        tree[child.v].d = d+1;
        int g = max(nowMax, child.w);
        gg[child.v] = g;
        //cout<<"node "<<child.v<<" parent "<<u<<" g "<<g<<" weight "<<child.w<<endl;
        make_tree(child.v, g, d+1);
    }
}

void solve() {
    int N; cin>>N;
    for(int i = 0; i < N-1; i++) {
        int u, v, w; cin>>u>>v>>w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    make_tree(1, 0);

    int res = 0;
    for (int i=1; i<N; i++) {
        for (int j=i+1; j<=N; j++) {
            int g = if_same_get_g(i, j);
            if (g != -1) {
                res += g; 
            } else {
                res += max(gg[i], gg[j]);
            }
        }
    }

    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}