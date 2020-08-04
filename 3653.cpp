#include <iostream>
#include <cstring>
using namespace std;

int tree[600001] = {0};
int pos[100001] = {0};
int S;
int query(int s, int e, int node, int start, int end) {
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
    int diff = tree[S+n] - val;
    for (int now = S+n; now>=1; now>>=1) {
        tree[now] -= diff;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int N, M; cin>>N>>M;
        for(S=1; S<N+M; S<<=1); // 트리 바닥 사이즈 S
        memset(tree, 0, sizeof(tree));
        memset(pos, 0, sizeof(pos));
        for (int i=0; i<N; i++) {
            tree[S+i] = 1;
            pos[N-i-1] = i;
        }
        int tail = N;
        for (int i=S-1; i>=1; i--) tree[i] = tree[i*2] + tree[i*2+1];
        while (M--) {
            int a; cin>>a;
            cout<<query(pos[a-1]+1, S, 1, 0, S)<<' ';
            change(pos[a-1], 0);
            pos[a-1] = tail;
            change(tail++, 1);
        }
        cout<<'\n';
    }
}