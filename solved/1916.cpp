#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const long MAX = 10000000001;
typedef pair<int, long> edge; // node, weight

long node[1001];
bool visited[1001] = {false};

struct cmp{
    bool operator()(pair<int, long> t, pair<int, long> u){
        return t.second > u.second;
    }
};

vector< vector<edge> > graph;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int V, E; cin>>V>>E;
    graph.resize(V+1);
    for (int v=0; v<=V; v++) node[v] = MAX;
    for (int e=0; e<E; e++) {
        int u, v, w; cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
    }
    int S, D; cin>>S>>D;
    node[S] = 0;
    priority_queue<pair<int, long>, vector<pair<int, long> >, cmp> pq;
    pq.push(make_pair(S, 0));
    while (!pq.empty()) {
        pair<int, int> now = pq.top(); pq.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        for (auto& e: graph[now.first]) {
            node[e.first] = min(now.second + e.second, node[e.first]);
            pq.push(make_pair(e.first, node[e.first]));
        }
    }
    cout<<node[D]<<endl;
}