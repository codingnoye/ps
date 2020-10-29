#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int N, M;
ull k;
int cost[10001];
int parent[10001];
bool visited[10001];

void uf_unite(int a, int b) {
    int tmp;
    while (parent[a]!=parent[b]) {
        // link by cost
        if (cost[parent[a]] < cost[parent[b]]) {
            tmp = parent[b];
            parent[b] = parent[a];
            b = tmp;
        } else {
            tmp = parent[a];
            parent[a] = parent[b];
            a = tmp;
        }
    }
}
int uf_find(int a) {
    int up;
    while(a != (up = parent[a])){
        int upp = parent[up];
        if(up != upp) parent[a] = upp;
        a = up;
    }
    return a;
}

void solve() {
    cin>>N>>M>>k;
    for (int i=0; i<N; i++) {
        cin>>cost[i];
        parent[i] = i;
    }
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        uf_unite(a-1, b-1);
    }
    ull res = 0;
    for (int i=0; i<N; i++) {
        int root = uf_find(i);
        if (!visited[root]) {
            visited[root] = true;
            res += cost[root];
        }
    }
    if (res<=k) cout<<res<<endl;
    else cout<<"Oh no"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}