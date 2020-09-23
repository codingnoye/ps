#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent0[200001];
int parent[200001];
int query[400001][3];
int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
}
void uf_union(int a, int b) {
    int pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return;
    parent[pa] = pb;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q; cin>>N>>Q;
    Q = N-1+Q;
    for (int i=1; i<=N; i++) {
        parent[i] = i;
    }
    for (int i=2; i<=N; i++) {
        cin>>parent0[i];
    }
    for (int i=0; i<Q; i++) {
        cin>>query[i][0];
        if (query[i][0]==0) cin>>query[i][1];
        else cin>>query[i][1]>>query[i][2];
    }
    stack<string> res;
    for (int i=Q-1; i>=0; i--) {
        if (query[i][0]==0) {
            uf_union(query[i][1], parent0[query[i][1]]);
        } else {
            res.push((uf_find(query[i][1])==uf_find(query[i][2])?"YES":"NO"));
        }
    }
    while (!res.empty()) {
        cout<<res.top()<<endl;
        res.pop();
    }
}