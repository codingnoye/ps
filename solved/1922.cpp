#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int parent[1001];
vector<pair<int, pair<int, int>>> edges;
int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
}

bool uf_union(int a, int b) {
    int pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return false;
    parent[min(pa, pb)] = max(pa, pb);
    return true;
}

void solve() {
    int N, M; cin>>N>>M;
    for (int i=1; i<=N; i++) parent[i] = i;
    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int res = 0;
    for (auto it=edges.begin(); it<edges.end(); it++) {
        if (uf_union(it->second.first, it->second.second)) {
            res += it->first;
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}