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

int N, Q;
int depth[100001];
bool visited[100001];
vector<vector<int>> graph;

void dfs(int i, int d) {
    if (visited[i]) return;
    visited[i] = true;
    depth[i] = d;
    for (auto n: graph[i]) {
        dfs(n, d+1);
    }
}

void solve() {
    cin>>N>>Q;
    graph.resize(N+1);
    for (int i=0; i<N-1; i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 1 = root
    dfs(1, 0);
    for (int i=0; i<Q; i++) {
        int a, b; cin>>a>>b;
        if ((300000 + depth[a] - depth[b]) % 2 == 0) {
            cout<<"Town"<<endl;
        } else {
            cout<<"Road"<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}