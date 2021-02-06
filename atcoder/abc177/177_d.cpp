#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > graph;
bool visited[200001] = {false};
int NOWLEN;

void dfs(int now) {
    if (visited[now]) return;
    visited[now] = true;
    NOWLEN++;
    for (auto it=graph[now].begin(); it<graph[now].end(); it++) {
        if (!visited[*it]) {
            dfs(*it);
        }
    }
}

int main() {
    int N, M; cin>>N>>M;
    graph.resize(N+1);
    for (int i=0; i<M; i++) {
        int A, B; cin>>A>>B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    int mx = 0;
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            NOWLEN = 0;
            dfs(i);
            mx = max(NOWLEN, mx);
        }
    }
    cout<<mx;
}