#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[1000001];
int uf_find(int x) {
    if (parent[x] == x) return x;
    return uf_find(parent[x]);
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
    while (M--) {
        int a, b, c; cin>>a>>b>>c;
        if (a==0) {
            uf_union(b, c);
        } else {
            cout<<(uf_find(b)==uf_find(c)?"YES":"NO")<<endl;
        }
    }
}