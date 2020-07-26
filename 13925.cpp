#include <iostream>
using namespace std;

typedef unsigned long long ull;
ull tree[131073*2];
ull A[131073*2]; //ax+b, {a, b}
ull B[131073*2];
const ull MOD = 1000000007ULL;
void apply(int node, int size) {
    if (A[node] != 1 || B[node] != 0) {
        if (size!=1) {
            A[node*2] = A[node*2]*A[node]; A[node*2] %= MOD;
            B[node*2] = B[node*2]*A[node]+B[node]; B[node*2] %= MOD;
            A[node*2+1] = A[node*2+1]*A[node]; A[node*2+1] %= MOD;
            B[node*2+1] = B[node*2+1]*A[node]+B[node]; B[node*2+1] %= MOD;
        }
        tree[node] = tree[node]*A[node];
        tree[node] %= MOD;
        tree[node] += B[node]*size;
        tree[node] %= MOD;
        A[node] = 1;
        B[node] = 0;
    }
}
void update(int s, int e, int a, int b, int node, int start, int size) {
    if (size==0) return;
    apply(node, size);
    if (s<=start && start+size<=e) {
        A[node] = a;
        B[node] = b;
        apply(node, size);
    } else if (start+size<=s || e<=start) {

    } else if (size>1) {
        const int newsize = size/2;
        update(s, e, a, b, node*2, start, newsize);
        update(s, e, a, b, node*2+1, start+newsize, newsize);
        tree[node] = tree[node*2] + tree[node*2+1];
        tree[node] %= MOD;
    }
}
int query(int s, int e, int node, int start, int size) {
    if (size==0) return 0;
    apply(node, size);
    if (s<=start && start+size<=e) {
        return tree[node];
    } else if (start+size<=s || e<=start) {
        return 0;
    } else if (size>1) {
        const int newsize = size/2;
        return (query(s, e, node*2, start, newsize) + query(s, e, node*2+1, start+newsize, newsize)) % MOD;
    } else {
        return tree[node];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    int S=1;
    while (S<N) S<<=1;
    //segtree initialize
    for (int i=1; i<2*S; i++) {
        tree[i] = 0;
        A[i] = 1;
        B[i] = 0;
    }
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        update(i, i+1, 0, x, 1, 0, S);
    }
    int M; cin>>M;
    while (M--) {
        int q; cin>>q;
        int x, y, v;
        if (q==9) {
            for (int node=1; node<2*S; node++) {
                cout<<"node "<<node<<" tree "<<tree[node]<<" A "<<A[node]<<" B "<<B[node]<<endl;
            }
            M++;
        } else if (q==1) {
            cin>>x>>y>>v;
            update(x-1, y, 1, v, 1, 0, S);
        } else if (q==2) {
            cin>>x>>y>>v;
            update(x-1, y, v, 0, 1, 0, S);
        } else if (q==3) {
            cin>>x>>y>>v;
            update(x-1, y, 0, v, 1, 0, S);
        } else {
            cin>>x>>y;
            cout<<(query(x-1, y, 1, 0, S)%MOD)<<'\n';
        }
    }
}