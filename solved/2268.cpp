#include <iostream>
using namespace std;

typedef long long lld;
lld tree[2097152] = {0};
int S = 1;
lld query(int s, int e, int node, int start, int end) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0;
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end);
    }
}
void change(int n, int val) {
    lld diff = tree[S+n] - val;
    for (int now = S+n; now>=1; now>>=1) {
        tree[now] -= diff;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q; cin>>N>>Q;
    for(; S<N; S<<=1);
    while (Q--) {
        int a, b, c; cin>>a>>b>>c;
        if (a==0) {
            if (b>c) swap(b, c);
            cout<<query(b-1, c, 1, 0, S)<<'\n';
        } else {
            change(b-1, c);
        }
    }
}