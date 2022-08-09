#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int SEG_SIZE = 1<<17;
// 1<<17 = 131072, 1<<20 = 1048576

struct node {
    int color=0, depth=999999999, id=0;
};

node op(node a, node b) {
    if (a.id == 0) return b;
    if (b.id == 0) return a;
    if (a.color < b.color) swap(a, b);
    if (a.color > b.color) return a;
    if (a.depth < b.depth) return a;
    return b;
}

struct Seg {
    node tree[SEG_SIZE << 1];
    int sz = SEG_SIZE;
    
    void init() {
        int x = sz-1;
        while (x) {
            tree[x] = op(tree[x << 1], tree[x << 1 | 1]); // op
            x--;
        }
    }

    void update(int x){
        x |= sz; 
        tree[x] = {1 - tree[x].color, tree[x].depth, tree[x].id}; // update
        while(x >>= 1){
            tree[x] = op(tree[x << 1], tree[x << 1 | 1]); // op
        }
    }

    // [l, r]
    node query(int l, int r){
        l |= sz, r |= sz;
        node ret = {0, 999999999, 0};
        while(l <= r){
            if(l & 1) ret = op(ret, tree[l++]); // op
            if(~r & 1) ret = op(ret, tree[r--]); // op
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

void update(int v){
    seg.update(in[v]);
}

node query(int a, int b){
    node ret = {0, 999999999, 0};
    // 다른 체인인 동안, 아래인 체인 끌어올림
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        ret = op(ret, seg.query(in[top[a]], in[a])); // op
        a = par[top[a]];
    }
    // 같은 체인
    if(dep[a] > dep[b]) swap(a, b);
    ret = op(ret, seg.query(in[a], in[b])); // op
    return ret;
}

int main() {
    fastio;
    int N; cin>>N;
    for (int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    dfs(); dfs1(); dfs2();
    
    for (int i=1; i<=N; i++) {
        seg.tree[seg.sz+in[i]] = {0, dep[i], i};
    }
    seg.init();

    int M; cin>>M;
    for (int i=0; i<M; i++) {
        int t, u; cin>>t>>u;
        if (t==1) {
            update(u);
        } else {
            node res = query(1, u);
            if (res.color == 0) cout<<"-1"<<endl;
            else cout<<res.id<<endl;
        }
    }
}