#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 3000001;
typedef pair<int, int> edge; // node, weight

int node[20001];
bool visited[20001] = {false};

struct cmp{
    bool operator()(pair<int, int> t, pair<int, int> u){
        return t.second > u.second;
    }
};

vector< vector<edge> > graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int V, E; cin>>V>>E;
    int K; cin>>K;
    graph.resize(V+1);
    for (int v=0; v<=V; v++) node[v] = MAX;
    node[K] = 0;
    for (int e=0; e<E; e++) {
        int u, v, w; cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(K, 0));
    while (!pq.empty()) {
        pair<int, int> now = pq.top(); pq.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        for (auto& e: graph[now.first]) {
            node[e.first] = min(now.second + e.second, node[e.first]);
            pq.push(make_pair(e.first, node[e.first]));
        }
    }
    for (int v=1; v<=V; v++) {
        if (node[v]==MAX) cout<<"INF\n";
        else cout<<node[v]<<'\n';
    }
}