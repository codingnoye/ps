#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

// 노드 번호: 0~N-1
int S; // 트리 종단 노드의 개수 
int H; // 트리의 높이 (노드 1개 -> 1, 노드 7개 -> 3, ...)
ll tree[4000000]; // 최대 크기는 가능한 최대 노드의 4배로 잡으면 안전
ll lazy[4000000];
void init(int n) {
    H = 0;
    for (S=1; S<n; S<<=1) {
        H++;
    }
    for (int i=0; i<2*S; i++) {
        tree[i] = 0; // 구간합이므로 기본값은 0
    }
}

void build () {
    for (int i=S-1; i>=1; i--)  {
        tree[i] = tree[i*2] + tree[i*2+1]; // 구간합이므로 더하기
    }
}

void apply_lazy(int node, int start, int end) {
    int size = end - start;
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * size;
        if (size > 1) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update(int s, int e, ll v, int node=1, int start=0, int end=S) {
    int size = end - start;
    apply_lazy(node, start, end);
    if (s<=start && end<=e) {
        lazy[node] += v;
        return v * size;
    } else if (e<=start || end<=s) {
        return 0;
    } else {
        ll diff = update(s, e, v, node*2, start, end-size/2) + update(s, e, v, node*2+1, start+size/2, end);
        tree[node] += diff;
        return diff;
    }
}

// 구간: [s, e)
// node: 현재 노드, start, end: 현재 노드의 범위
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    apply_lazy(node, start, end);   
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0;
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end);
    }
}

void solve() {
    int n, m, k; cin>>n>>m>>k;
    init(n);
    for (int i=0; i<n; i++) cin>>tree[S+i];
    build();
    for (int i=0; i<m+k; i++) {
        ll a; cin>>a;
        if (a == 1) {
            int s, e; cin>>s>>e;
            ll res = query(s-1, e);
            cout<<res<<endl;
        } else {
            int s, e; cin>>s>>e;
            ll v; cin>>v;
            update(s-1, e, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}