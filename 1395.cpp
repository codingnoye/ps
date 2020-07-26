#include <iostream>
using namespace std;
const int SUM = 0;
const int LAZY = 1;
int res;
int tree[131072*2+10];
bool lazy[131072*2+10];
void update(int s, int e, int node, int start, int size) {
    if (size==0) return;
    if (lazy[node]) {
        tree[node] = size - tree[node];
        lazy[node] = false;
        if (size != 1) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
    }
    if (s<=start && start+size<=e) {
        if (size == 1) { // 포함된 리프 노드인 경우
            tree[node] = 1 - tree[node];
        } else { // 포함된 서브트리인 경우
            tree[node] = size - tree[node];
            lazy[node*2] = 1-lazy[node*2];
            lazy[node*2+1] = 1-lazy[node*2+1];
        }
    } else if (start+size<=s || e<=start) {

    } else {
        const int newsize = size/2;
        update(s, e, node*2, start, newsize);
        update(s, e, node*2+1, start+newsize, newsize);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
int query(int s, int e, int node, int start, int size) {
    //cout<<"query "<<s<<" "<<e<<" "<<start<<" "<<start+size<<endl;
    if (size==0) return 0;
    if (lazy[node]) {
        tree[node] = size - tree[node];
        lazy[node] = false;
        if (size != 1) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
    }
    if (s<=start && start+size<=e) {
        return tree[node];
    } else if (start+size<=s || e<=start) {
        return 0;
    } else {
        const int newsize = size/2;
        return query(s, e, node*2, start, newsize) + query(s, e, node*2+1, start+newsize, newsize);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin>>N>>M;
    int S=1;
    while (S<N) S<<=1;
    //segtree initialize
    for (int i=1; i<2*S; i++) {
        tree[i] = 0;
        lazy[i] = false;
    }
    int a, b, c;
    while (M--) {
        cin>>a>>b>>c;
        if (a==1) {
            cout<<query(b-1, c, 1, 0, S)<<'\n';
        } else if (a==2) {
            for (int i=1; i<2*S; i++) {
                cout<<"node "<<i<<" "<<tree[i]<<" "<<lazy[i]<<endl;
            }
        } else {
            update(b-1, c, 1, 0, S);
        }
    }
}