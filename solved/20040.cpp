#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int parent[500001];

int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
}

bool uf_union(int x, int y) {
    int px = uf_find(x);
    int py = uf_find(y);
    if (px == py) return false;
    parent[px] = py;
    return true;
}

void solve() {
    int N, M; cin>>N>>M;
    for (int i=0; i<=N; i++) {
        parent[i] = i;
    }
    int found = 0;
    for (int i=0; i<M; i++) {
        int x, y; cin>>x>>y;
        if (found == 0 && !uf_union(x, y)) {
            found = i+1;
        }
    }
    cout<<found<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}