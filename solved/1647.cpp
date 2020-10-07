#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

struct Edge {
    int a;
    int b;
    int c;
};

bool operator<(Edge a, Edge b) {
    return a.c < b.c;
}

vector<Edge> edges;

int parent[100001];
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

void solve() {
    int N, M; cin>>N>>M;
    while (M--) {
        int a, b, c; cin>>a>>b>>c;
        edges.push_back(Edge {a, b, c});
    }
    sort(edges.begin(), edges.end());
    for (int i=1; i<=N; i++) parent[i] = i;
    int res = 0;
    int last = 0;
    for (auto it=edges.begin(); it<edges.end(); it++) {
        if (uf_find((*it).a) != uf_find((*it).b)) {
            uf_union((*it).a, (*it).b);
            res += (*it).c;
            last = (*it).c;
        }
    }
    cout<<(res-last)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}