#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<unordered_set<int>> G(N+1);
    vector<bool> visited(N+1); visited[0] = true;
    for (int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    vector<int> visits(N);
    for (int i=0; i<N; i++) cin>>visits[i];

    stack<int> history;
    int valid = 1;
    for (int i=0; i<N-1; i++) {
        int now = visits[i];
        int next = visits[i+1];

        while (G[now].find(next) == G[now].end() && !history.empty()) {
            now = history.top(); history.pop();
        }
        if (G[now].find(next) == G[now].end()) {
            valid = 0;
            break;
        }
        if (visited[next]) {
            valid = 0;
            break;
        }
        history.push(now);
    }
    if (visits[0] != 1) valid = 0;

    cout<<valid<<endl;
}