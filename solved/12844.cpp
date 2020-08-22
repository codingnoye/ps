#include <iostream>
using namespace std;
int tree[524289*2];
int lazy[524289*2];
void update(int s, int e, int k, int node, int start, int size) {
    if (size==0) return;
    if (lazy[node]>0) {
        if (size != 1) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        } else {
            tree[node] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    if (s<=start && start+size<=e) {
        if (size == 1) { // 포함된 리프 노드인 경우
            tree[node] ^= k;
        } else { // 포함된 서브트리인 경우
            lazy[node*2] ^= k;
            lazy[node*2+1] ^= k;
        }
    } else if (start+size<=s || e<=start) {

    } else {
        const int newsize = size/2;
        update(s, e, k, node*2, start, newsize);
        update(s, e, k, node*2+1, start+newsize, newsize);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}
int query(int s, int e, int node, int start, int size) {
    //cout<<"query "<<s<<" "<<e<<" "<<start<<" "<<start+size<<endl;
    if (size==0) return 0;
    if (lazy[node]>0) {
        if (size != 1) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        } else {
            tree[node] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    if (s<=start && start+size<=e) {
        return tree[node];
    } else if (start+size<=s || e<=start) {
        return 0;
    } else {
        const int newsize = size/2;
        return query(s, e, node*2, start, newsize) ^ query(s, e, node*2+1, start+newsize, newsize);
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
        lazy[i] = 0;
    }
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        update(i, i+1, x, 1, 0, S);
    }
    int M; cin>>M;
    while (M--) {
        int q; cin>>q;
        if (q==0) {
            for (int node=1; node<2*S; node++) {
                cout<<"node "<<node<<" "<<tree[node]<<" "<<lazy[node]<<endl;
            }
        } else if (q==2) {
            int i, j; cin>>i>>j;
            if (i>j) swap(i, j);
            cout<<query(i, j+1, 1, 0, S)<<'\n';
        } else {
            int i, j, k; cin>>i>>j>>k;
            if (i>j) swap(i, j);
            update(i, j+1, k, 1, 0, S);
        }
    }
}