#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<vector<int>> near;
int parent[100001];

void dfs(int now, int from) {
    parent[now] = from;
    for (int i=0; i<near[now].size(); i++) {
        if (near[now][i] != from) {
            dfs(near[now][i], now);
        }
    }
}

void solve() {
    int N; cin>>N;
    near.resize(N+1);
    for (int _=0; _<N-1; _++) {
        int a, b; cin>>a>>b;
        near[a].push_back(b);
        near[b].push_back(a);
    }
    dfs(1, 1);
    for (int i=2; i<=N; i++) {
        cout<<parent[i]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}