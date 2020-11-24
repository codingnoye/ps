#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int N, M; 
vector<vector<int>> graph;
vector<vector<ii>> blueprint;
int in_degree[100];
int need[100];
void after(int a, int b) {
    graph[a].push_back(b);
    in_degree[b]++;
}

void topo_sort(vector<int>& res) {
    queue<int> q;
    for (int i=0; i<N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        res.push_back(now);
        q.pop();
        for (int edge: graph[now]) {
            if (--(in_degree[edge]) == 0) q.push(edge);
        }
    }
}

void solve() {
    cin>>N>>M;
    graph.resize(N);
    blueprint.reserve(N);

    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        after(b-1, a-1);
        blueprint[a-1].push_back({b-1, c});
    }
    vector<int> res;
    topo_sort(res);
    need[N-1] = 1;
    for (auto it=res.rbegin(); it<res.rend(); it++) {
        if (blueprint[*it].size() == 0) continue;
        for (ii now: blueprint[*it]) {
            need[now.first] += need[*it] * now.second;
        }
        need[*it] = 0;
    }
    for (int i=0; i<N; i++) if (need[i] != 0) cout<<(i+1)<<' '<<need[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}