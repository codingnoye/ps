#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<vector<int>> graph;
int visited[20001];

void solve() {
    int K; cin>>K;
    while (K--) {
        int V, K; cin>>V>>K;
        for (int i=1; i<=V; i++) visited[i] = -1;
        vector<vector<int>>().swap(graph);
        graph.resize(V+1);
        for (int i=0; i<K; i++) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool res = true;
        queue<pair<int, int>> Q;
        for (int i=1; i<=V; i++) {
            if (visited[i] == -1) {
                Q.push({i, 0});
            }
            while (!Q.empty()) {
                int now = Q.front().first;
                int group = Q.front().second;
                Q.pop();
                for (auto it=graph[now].begin(); it<graph[now].end(); it++) {
                    if (visited[*it] == -1) {
                        Q.push({*it, group==1?0:1});
                        visited[*it] = group==1?0:1;
                    } else if (visited[*it] == group) {
                        queue<pair<int, int>>().swap(Q);
                        res = false;
                        break;
                    }
                }
            }
        }
        cout<<(res?"YES":"NO")<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}