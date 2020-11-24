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

int N, M; 
vector<vector<int>> graph;
int in_degree[500];
bool visited[500];

void after(int a, int b) {
    graph[a].push_back(b);
    in_degree[b]++;
}

vector<int>& topo_sort() {
    vector<int> res;
    queue<int> q;
    for (int i=0; i<N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        res.push_back(now+1);
        for (int edge: graph[now]) {
            if (--(in_degree[edge]) == 0) q.push(edge);
        }
    }
}

void solve() {
    cin>>N>>M;
    graph.resize(N);

    for (int m=0; m<M; m++) {
        int a, b; cin>>a>>b;
        after(a-1, b-1);
    }

    vector<int>& res = topo_sort();
    for (int i: res) cout<<i<<' ';
    // if (res.size() == N) for (int i: res) cout<<i<<endl;
    //else cout<<0<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}