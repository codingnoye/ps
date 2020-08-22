#include <iostream>
using namespace std;

typedef long long lld;
lld tree[300001] = {0};
int S = 1;
lld query(int s, int e, int node, int start, int end) { //start<=N<end
    int size = end - start;
    //cout<<s<<" "<<e<<" "<<node<<" "<<start<<" "<<end<<endl;
    if (s<=start && end<=e) {
        //cout<<tree[node]<<"!"<<endl;
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
    for(; S<N; S<<=1); // 트리 바닥 사이즈 S
    for (int i=0; i<N; i++) cin>>tree[S+i];
    for (int i=S-1; i>=1; i--) tree[i] = tree[i*2] + tree[i*2+1];
    while (Q--) {
        int x, y, a, b; cin>>x>>y>>a>>b;
        if (x>y) swap(x, y);
        cout<<query(x-1, y, 1, 0, S)<<'\n';
        change(a-1, b);
    }
}