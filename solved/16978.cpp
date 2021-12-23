// #2042 구간 합 구하기

#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long ll;

// 노드 번호: 0~N-1
int S; // 트리 종단 노드의 개수 
int H; // 트리의 높이 (노드 1개 -> 1, 노드 7개 -> 3, ...)
ll tree[4000000]; // 최대 크기는 가능한 최대 노드의 4배로 잡으면 안전

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

void update(int x, ll v) {
    int now = S+x;
    tree[now] = v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = tree[now*2] + tree[now*2+1]; // 구간합이므로 더하기
    }
}

// 구간: [s, e)
// node: 현재 노드, start, end: 현재 노드의 범위
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0;
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end);
    }
}

struct Query {
    ll a, b, c, d, origin;
};
bool operator<(Query a, Query b) {
    return (a.b == b.b) ? a.a<b.a : a.b<b.b;
}

void solve() {
    int n; cin>>n;
    
    init(n);
    for (int i=0; i<n; i++) cin>>tree[S+i];
    build();
    int Q; cin>>Q;
    vector<Query> qs;
    int q1i = 1;
    int q2i = 0;
    while (Q--) {
        int a; cin>>a;
        if (a==1) {
            int b, c; cin>>b>>c;
            qs.push_back({a, q1i++, b, c, 0});
        } else {
            int b, c, d; cin>>b>>c>>d;
            qs.push_back({a, b, c, d, q2i++});
        }
    }
    sort(qs.begin(), qs.end());
    vector<pair<ll, ll>> rs;
    for (int i=0; i<qs.size(); i++) {
        auto [a, b, c, d, o] = qs[i];
        if (a == 1) {
            update(c-1, d);
        } else {
            ll res = query(c-1, d);
            rs.push_back({o, res});
        }
    }
    sort(rs.begin(), rs.end());
    for (auto r: rs) cout<<r.second<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}