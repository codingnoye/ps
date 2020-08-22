#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[100001][21] = {0}; //parent[x][y] = 2^yth parent of x
int depth[100001] = {0};
vector<vector<int> > graph;

int main() {
    int N; scanf("%d", &N);
    graph.resize(N+1);
    for (int i=2; i<=N; i++) {
        int a, b; scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    parent[0][0] = 0;
    parent[1][0] = 1;
    depth[1] = 1;
    queue<int> q;
    q.push(1);
    // 트리 빌드
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int to: graph[now]) {
            if (parent[to][0]==0) { // 방문 체크
                parent[to][0] = now;
                depth[to] = depth[now]+1;
                q.push(to);
            }
        }
    }
    for (int j=1; j<21; j++) {
        for (int i=1; i<=N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    int M; scanf("%d", &M);
    while (M--) {
        int a, b; scanf("%d %d", &a, &b);
        if (depth[a] <= depth[b]) swap(a, b);
        while (depth[a] > depth[b]) {
            int delta = depth[a] - depth[b];
            int s=0;
            for (int i=1; i<=delta; i<<=1) s++; // 1 2 4 8 / 0 1 2 3
            a = parent[a][s-1];
        }
        while (a!=b) {
            int i;
            for (i=1; parent[a][i]!=parent[b][i]; i++);
            a = parent[a][i-1];
            b = parent[b][i-1];
        }
        printf("%d\n", a);
    }
}