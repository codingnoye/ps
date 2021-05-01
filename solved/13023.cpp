#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int N, M;
bool visited[2000];
vector<vector<int>> graph;

bool dfs(int x, int d) {
    if (visited[x]) return false;
    if (d>=5) return true;
    visited[x] = true;
    for (auto f: graph[x]) {
        bool res = dfs(f, d+1);
        if (res) return true;
    }
    visited[x] = false;
    return false;
}

void solve() {
    cin>>N>>M;
    graph.resize(N);
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=0; i<N; i++) {
        for (int i=0; i<N; i++) visited[i] = false;
        if (dfs(i, 1)) {
            cout<<1<<endl;
            return;
        }
    }
    cout<<0<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}