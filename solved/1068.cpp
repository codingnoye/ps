#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;

int parents[51];
int dfs(int i) {
    if (graph[i].size() == 0) return 1;
    int s = 0;
    for (int j: graph[i]) s += dfs(j);
    return s;
}
void solve() {
    int N; cin>>N;
    int root;
    graph.resize(N);
    for (int i=0; i<N; i++) {
        int p; cin>>p;
        parents[i] = p;
        if (p!=-1)
            graph[p].push_back(i);
        else
            root = i;
    }
    int d; cin>>d;
    if (d==root) {
        cout<<0<<endl;
        return;
    }
    vector<int> newsibling;
    for (int i: graph[parents[d]]) {
        if (i != d) newsibling.push_back(i);
    }
    graph[parents[d]] = newsibling;

    cout<<dfs(root)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}