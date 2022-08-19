#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int SEG_SIZE = 1<<17;
// 1<<17 = 131072, 1<<20 = 1048576
struct Seg {
    ll tree[SEG_SIZE << 1];
    int sz = SEG_SIZE;
    
    void init() {
        int x = sz-1;
        while (x) {
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]); // op
            x--;
        }
    }

    void update(int x, ll v){
        x |= sz; 
        tree[x] = v; // update
        while(x >>= 1){
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]); // op
        }
    }

    // [l, r]
    ll query(int l, int r){
        l |= sz, r |= sz;
        ll ret = 0;
        while(l <= r){
            if(l & 1) ret = max(ret, tree[l++]);
            if(~r & 1) ret = max(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
} seg;

const int MAXV = 101010;
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV];
// 크기, 깊이, 부모, 체인의 top, dfs ordering
// 세그트리 인덱싱: in[i]
vector<int> childs[MAXV]; // 자식
vector<int> inp[MAXV]; //입력 / 양방향 그래프

int chk[MAXV];
void dfs(int v = 1){
	chk[v] = 1;
	for(auto i : inp[v]){
		if(chk[i]) continue;
		chk[i] = 1;
		childs[v].push_back(i);
		dfs(i);
	}
}

void dfs1(int v = 1){
	sz[v] = 1;
	for(auto &i : childs[v]){
		dep[i] = dep[v] + 1; par[i] = v;
		dfs1(i); sz[v] += sz[i];
		if(sz[i] > sz[childs[v][0]]) swap(i, childs[v][0]);
	}
}

int pv;
void dfs2(int v = 1){
	in[v] = ++pv;
	for(auto i : childs[v]){
		top[i] = i == childs[v][0] ? top[v] : i;
		dfs2(i);
	}
	out[v] = pv;
}

void update(int v, int w){
    seg.update(in[v], w);
}

ll query(int a, int b){
    ll ret = 0;
    // 다른 체인인 동안, 아래인 체인 끌어올림
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret = max(ret, seg.query(in[top[a]], in[a])); // op
        a = par[top[a]];
    }
    // 같은 체인
    if(dep[a] > dep[b]) swap(a, b);
    ret = max(ret, seg.query(in[a]+1, in[b])); // op
    return ret;
}

int main() {
    fastio;
    int N, Q; cin>>N;

    vector<pair<pair<pair<int, int>, int>, int>> inps;
    vector<int> edge_to_node(N);
    for (int i=0; i<N-1; i++) {
        int u, v, w; cin>>u>>v>>w;
        inp[u].push_back(v);
        inp[v].push_back(u);
        inps.push_back({{{u, v}, i+1}, w});
        inps.push_back({{{v, u}, i+1}, w});
    }
    dfs(); dfs1(); dfs2();

    for (auto& [edge, w]: inps) {
        auto [uv, id] = edge;
        auto [u, v] = uv;
        if (par[u] != v) continue;
        update(u, w);
        edge_to_node[id] = u;
    }

    cin>>Q;

    while (Q--) {
        int t, u, v; cin>>t>>u>>v;
        if (t==1) {
            update(edge_to_node[u], v);
        } else {
            cout<<query(u, v)<<endl;
        }
    }
}