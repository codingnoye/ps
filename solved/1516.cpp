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
int cost[500];
int endtime[500];
void after(int a, int b) {
    graph[a].push_back(b);
    in_degree[b]++;
}

void topo_sort() {
    queue<int> q;
    for (int i=0; i<N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (int edge: graph[now]) {
            if (--(in_degree[edge]) == 0) q.push(edge);
            endtime[edge] = max(endtime[now]+cost[edge], endtime[edge]);
        }
    }
}

void solve() {
    cin>>N;
    graph.resize(N);

    for (int i=0; i<N; i++) {
        cin>>cost[i];
        endtime[i] = cost[i];
        int x; cin>>x;
        while (x!=-1) {
            after(x-1, i);
            cin>>x;
        }
    }
    topo_sort();
    for (int i=0; i<N; i++) cout<<endtime[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}