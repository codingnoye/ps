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

vector<vector<int>> graph;
int in_degree[32000];
bool visited[32000];

void after(int a, int b) {
    graph[a].push_back(b);
    in_degree[b]++;
}

void solve() {
    int N, M; cin>>N>>M;
    graph.resize(N);

    for (int m=0; m<M; m++) {
        int a, b; cin>>a>>b;
        after(a-1, b-1);
    }

    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<N; i++) {
        if (in_degree[i] == 0) pq.push(i);
    }
    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        if (visited[now]) continue;
        res.push_back(now+1);
        for (int edge: graph[now]) {
            if (--(in_degree[edge]) == 0) pq.push(edge);
        }
    }
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