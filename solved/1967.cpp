#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int N;
map<int, vector<ii>> graph;
bool visited[10001];
int dist[10001];

void visit(int n, int d) {
    visited[n] = true;
    dist[n] = d;
    for (ii neigh: graph[n]) {
        if (!visited[neigh.first]) {
            visit(neigh.first, d+neigh.second);
        }
    }
}
ii maxfrom(int s) {
    for (int i=0; i<10001; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    visit(s, 0);
    int m = (int) (max_element(dist, dist+10001) - dist);
    int md = dist[m];
    return {m, md};
}

void solve() {
    cin>>N;
    for (int i=0; i<N-1; i++) {
        int a, b, c; cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    ii a = maxfrom(1);
    ii b = maxfrom(a.first);
    cout<<b.second<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}