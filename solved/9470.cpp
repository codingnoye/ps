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
int in_degree[1000];
int mx[1000];
int mxc[1000];
int sth[1000];
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
        sth[now] = mxc[now]==1?mx[now]:mx[now]+1;
        for (int edge: graph[now]) {
            if (--(in_degree[edge]) == 0) q.push(edge);
            if (mx[edge] < sth[now]) {
                mx[edge] = sth[now];
                mxc[edge] = 1;
            } else if (mx[edge] == sth[now]) mxc[edge]++;
        }
    }
}

void solve() {
    int T; cin>>T;
    while (T--) {
        int K;
        cin>>K>>N>>M;
        graph.clear();
        graph.resize(N);
        for (int i=0; i<N; i++) {
            in_degree[i] = mx[i] = mxc[i] = sth[i] = 0;
        }

        for (int i=0; i<M; i++) {
            int a, b; cin>>a>>b;
            after(a-1, b-1);
        }

        sth[0] = 1;
        vector<int> res;
        topo_sort(res);
        cout<<K<<' '<<sth[N-1]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}