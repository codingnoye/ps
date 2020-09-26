#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[51];
int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
}
void uf_union(int a, int b) {
    int pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return;
    parent[min(pa, pb)] = max(pa, pb);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin>>N>>M;
    for (int i=0; i<=N; i++) {
        parent[i] = i;
    }
    int X; cin>>X;
    for (int i=0; i<X; i++) {
        int x; cin>>x;
        parent[x] = 0;
    }
    int res = 0;
    int firsts[51] = {0};
    for (int j=0; j<M; j++) {
        int x; cin>>x;
        int first; cin>>first;
        firsts[j] = first;
        for (int i=1; i<x; i++) {
            int n; cin>>n;
            uf_union(first, n);
        }
    }
    for (int j=0; j<M; j++) {
        if (uf_find(firsts[j]) != uf_find(0)) {
            res++;
        }
    }
    cout<<res<<endl;
}