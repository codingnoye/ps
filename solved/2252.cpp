#include <iostream>
#include <queue>
#include <map>
using namespace std;
int inputs[32001] = {0};
vector<vector<int> > graph;
int main() {
    int N, M; cin>>N>>M;
    graph.resize(N+1);
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        inputs[b]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (inputs[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        cout<<now<<' ';
        q.pop();
        for (auto it = graph[now].begin(); it!=graph[now].end(); it++) {
            if (--inputs[*it] == 0) {
                q.push(*it);
            }
        }
    }
}