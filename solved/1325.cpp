#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;

struct node {
    vector<int> childs;
};

node graph[10001];
bool visited[10001];

int count_child(int node_id) {
    if (visited[node_id]) return 0;
    visited[node_id] = true;
    int count = 1;
    for (int child : graph[node_id].childs) {
        count += count_child(child);
    }
    return count;
}

void solve() {
    int N, M; cin>>N>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        graph[b].childs.push_back(a);
    }
    vector<pair<int, int>> counts;
    for (int i=1; i<=N; i++) {
        counts.push_back({count_child(i), i});
        fill(visited, visited+10001, false);
    }
    int maxcnt = max_element(counts.begin(), counts.end())->first;
    vector<int> max_roots;
    for (int i=0; i<counts.size(); i++) {
        if (counts[i].first == maxcnt) {
            max_roots.push_back(counts[i].second);
        }
    }
    sort(max_roots.begin(), max_roots.end());
    for (int root : max_roots) {
        cout<<root<<' ';
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}