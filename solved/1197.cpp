#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[10001];
struct edge{
    int a;
    int b;
    int w;
};
bool operator<(edge a, edge b) {
    return a.w<b.w;
}
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
    int V, E; cin>>V>>E;
    for (int i=1; i<=V; i++) parent[i] = i;
    vector<edge> ve;
    for (int i=0; i<E; i++) {
        int a, b, w; cin>>a>>b>>w;
        ve.push_back(edge{a, b, w});
    }
    sort(ve.begin(), ve.end());
    int res = 0;
    for (auto it=ve.begin(); it!=ve.end(); it++) {
        edge e = *it;
        if (uf_find(e.a) != uf_find(e.b)) {
            res += e.w;
            uf_union(e.a, e.b);
        }
    }
    cout<<res<<endl;
}