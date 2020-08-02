#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int parent[100001][21] = {0}; //parent[x][y] = 2^yth parent of x
int mindis[100001][21] = {0};
int maxdis[100001][21] = {0};
int depth[100001] = {0};
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
                mindis[to.first][0] = to.second;
                maxdis[to.first][0] = to.second;
                depth[to.first] = depth[now]+1;
                q.push(to.first);
            }
        }
    }
    for (int j=1; j<18; j++) {
        for (int i=1; i<=N; i++) {
            maxdis[i][j] = max(maxdis[i][j-1], maxdis[parent[i][j-1]][j-1]);
            mindis[i][j] = min(mindis[i][j-1], mindis[parent[i][j-1]][j-1]);
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    int M; scanf("%d", &M);
    while (M--) {
        int a, b; scanf("%d %d", &a, &b);
        if (depth[a] <= depth[b]) swap(a, b);
        int mn = 1000000;
        int mx = 0;
        while (depth[a] > depth[b]) {
            int delta = depth[a] - depth[b];
            int s=0;
            for (int i=1; i<=delta; i<<=1) s++; // 1 2 4 8 / 0 1 2 3
            mn = min(mindis[a][s-1], mn);
            mx = max(maxdis[a][s-1], mx);
            a = parent[a][s-1];
        }
        while (a!=b) {
            int i;
            for (i=1; parent[a][i]!=parent[b][i]; i++);
            mn = min(mindis[a][i-1], mn);
            mx = max(maxdis[a][i-1], mx);
            mn = min(mindis[b][i-1], mn);
            mx = max(maxdis[b][i-1], mx);
            a = parent[a][i-1];
            b = parent[b][i-1];
        }
        printf("%d %d\n", mn, mx);
    }
}