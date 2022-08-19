#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
// #define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> graph_raw; // vec<vec<dest, label>>
vector<vector<pair<int, int>>> graph; // vec<vec<dest, weight>>

bool dfs(int i, vector<bool>& visited) {
    if (visited[i]) return true;
    visited[i] = true;
    for (auto& [j, weight] : graph[i]) {
        if (weight == 0 && dfs(j, visited)) return true;
    }
    return false;
}

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int ans = 0;
        int N, M, K; cin>>N>>M>>K;

        graph_raw = vector<vector<pair<int, int>>>(N);
        graph = vector<vector<pair<int, int>>>(N);
        for (int i=0; i<M; i++) {
            int u, v; string label; cin>>u>>v>>label;
            graph_raw[u-1].push_back({v-1, label[0]-'A'});
        }

        for (int i=0; i<N; i++) {
            for (auto& [j, ij_label] : graph_raw[i]) {
                for (auto& [k, jk_label]: graph_raw[j]) {
                    if (i==k) continue;
                    if ((ij_label+1)%3 == jk_label || K==-1) {
                        graph[i].push_back({k, 0});
                    } else {
                        graph[i].push_back({k, 1});
                    }
                }
            }
        }

        vector<bool> visited(N, false);
        for (int i=0; i<N; i++) {
            if (visited[i]) continue;
            if (dfs(i, visited)) {
                ans = -1;
                break;
            }
        }

        if (ans != 1) {
            // find max node length on route length K
            int max_length = 0;
        }

        cout<<"Case #"<<t<<endl<<ans<<endl;
    }
}