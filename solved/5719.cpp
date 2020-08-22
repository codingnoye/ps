#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10000001;
typedef pair<int, int> edge; // node, weight



struct cmp{
    bool operator()(pair<int, int> t, pair<int, int> u){
        return t.second > u.second;
    }
};

int node[501];
bool visited[501];

priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
vector< vector<edge> > graph;
vector< vector< pair<int, int> > > previous; // node, edge_index
// previous[node][n_th previous]
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true){
        // 초기화
        int N, P; cin>>N>>P;
        if (!N && !P) break;
        int S, D; cin>>S>>D;
        graph.resize(N);
        previous.resize(N);
        for (int p=0; p<P; p++) {
            int u, v, w; cin>>u>>v>>w;
            graph[u].push_back(make_pair(v, w));
        }
        // 다익스트라
        for (int n=0; n<N; n++) {
            node[n] = MAX;
            visited[n] = false;
        }
        node[S] = 0;
        
        pq.push(make_pair(S, 0));
        while (!pq.empty()) {
            pair<int, int> now = pq.top(); pq.pop();
            if (visited[now.first]) continue;
            visited[now.first] = true;
            for (int i=0; i<graph[now.first].size(); i++) {
                edge& e = graph[now.first][i];
                if (node[e.first] > now.second + e.second) {
                    previous[e.first].clear();
                }
                if (node[e.first] >= now.second + e.second) {
                    node[e.first] = now.second + e.second;
                    previous[e.first].push_back(make_pair(now.first, i));
                    pq.push(make_pair(e.first, node[e.first]));
                }
            }
        }

        // 최단경로 길이 구하기
        int shortest = node[D];
        // 최단경로 루트 제거
        queue<int> q;
        q.push(D);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            if (now==S) continue;
            for (auto prev: previous[now]) {
                graph[prev.first][prev.second].second = MAX;
                q.push(prev.first);
            }
        }

        // 다익스트라
        for (int n=0; n<N; n++) {
            node[n] = MAX;
            visited[n] = false;
        }
        previous.clear();
        previous.resize(N);
        node[S] = 0;
        previous[S].push_back(make_pair(-1, 0));
        
        pq.push(make_pair(S, 0));
        while (!pq.empty()) {
            pair<int, int> now = pq.top(); pq.pop();
            if (visited[now.first]) continue;
            visited[now.first] = true;
            for (int i=0; i<graph[now.first].size(); i++) {
                edge& e = graph[now.first][i];
                if (node[e.first] > now.second + e.second) {
                    previous[e.first].clear();
                }
                if (node[e.first] >= now.second + e.second) {
                    node[e.first] = now.second + e.second;
                    previous[e.first].push_back(make_pair(now.first, i));
                    pq.push(make_pair(e.first, node[e.first]));
                }
            }
        }

        if (node[D]==MAX) cout<<"-1\n";
        else cout<<node[D]<<'\n';
        graph.clear();
        previous.clear();
    }
}