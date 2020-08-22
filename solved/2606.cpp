#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > graph;
bool visited[101] = {false};

int main() {
    int N, E; cin>>N>>E;
    graph.resize(N+1);
    for (int i=0; i<E; i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (int near: graph[now]) Q.push(near);
    }
    int count = -1;
    for (int i=1; i<=N; i++) if (visited[i]) count++;
    cout<<count<<endl;
}