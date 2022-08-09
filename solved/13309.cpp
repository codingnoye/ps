#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int SEG_SIZE = 1<<18;
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

const int MAXV = 201010;
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
    int N, Q; cin>>N>>Q;

    for (int i=2; i<=N; i++) {
        int x; cin>>x;
        inp[x].push_back(i);
        inp[i].push_back(x);
    }
    dfs(); dfs1(); dfs2();
    while (Q--) {
        int b, c, d; cin>>b>>c>>d;
        int res = query(b, c);
        if (d == 0) {
            cout<<(res==0?"YES":"NO")<<endl;
        } else {
            if (res == 0) {
                cout<<"YES"<<endl;
                update(b, 1);
            } else {
                cout<<"NO"<<endl;
                update(c, 1);
            }
        }
    }
}