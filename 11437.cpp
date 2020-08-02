#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[50001] = {0};
int depth[50001] = {0};
vector<vector<int> > graph;

int main() {
    int N; cin>>N;
    graph.resize(N+1);
    for (int i=2; i<=N; i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    parent[1] = 1;
    depth[1] = 1;
    queue<int> q;
    q.push(1);
    // 트리 빌드
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int to: graph[now]) {
            if (parent[to]==0) { // 방문 체크
                parent[to] = now;
                depth[to] = depth[now]+1;
                q.push(to);
            }
        }
    }
    int M; cin>>M;
    while (M--) {
        int a, b; cin>>a>>b;
        if (depth[a] <= depth[b]) swap(a, b);
        while (depth[a] > depth[b]) {
            a = parent[a];
        }
        while (a!=b) {
            a = parent[a];
            b = parent[b];
        }
        cout<<a<<'\n';
    }
}