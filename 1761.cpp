#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[40001][18] = {0}; //parent[x][y] = 2^yth parent of x
long long dist[40001][18] = {0};
int depth[40001] = {0};
typedef pair<int, int> ii;
vector<vector<ii> > graph;

int main() {
    int N; scanf("%d", &N);
    graph.resize(N+1);
    for (int i=1; i<N; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));

    }
    int R = 1;
    // for (int i=1; i<=N; i++) if (graph[i].size()==2) {
    //     R = i;
    //     break;
    // }
    depth[R] = 1;
    queue<int> q;
    q.push(R);
    // 트리 빌드
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (ii to: graph[now]) {
            if (parent[to.first][0]==0 && to.first != R) { // 방문 체크
                parent[to.first][0] = now;
                dist[to.first][0] = to.second;
                depth[to.first] = depth[now]+1;
                q.push(to.first);
            }
        }
    }
    for (int j=1; j<18; j++) {
        for (int i=1; i<=N; i++) {
            dist[i][j] = dist[i][j-1] + dist[parent[i][j-1]][j-1];
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    int M; scanf("%d", &M);
    while (M--) {
        int a, b; scanf("%d %d", &a, &b);
        if (depth[a] <= depth[b]) swap(a, b);
        long long totaldist = 0;
        while (depth[a] > depth[b]) {
            int delta = depth[a] - depth[b];
            int s=0;
            for (int i=1; i<=delta; i<<=1) s++; // 1 2 4 8 / 0 1 2 3
            totaldist += dist[a][s-1];
            a = parent[a][s-1];
        }
        while (a!=b) {
            int i;
            for (i=1; parent[a][i]!=parent[b][i]; i++);
            totaldist += dist[a][i-1];
            totaldist += dist[b][i-1];
            a = parent[a][i-1];
            b = parent[b][i-1];
        }
        printf("%lld\n", totaldist);
    }
}