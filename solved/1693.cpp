#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int max_color = 19;

ll dp[100001][max_color+1];
vector<vector<int>> al(100001);

ll dfs(int node, int color, int from = -1) {
    if (dp[node][color] != 0) return dp[node][color];
    ll cost = color;

    for (int child: al[node]) {
        if (child == from) continue;

        ll min_of_child = 999999999999;
        for (int c=1; c<=max_color; c++) {
            if (c == color) continue;
            min_of_child = min(min_of_child, dfs(child, c, node));
        }
        cost += min_of_child;
    }
    dp[node][color] = cost;
    return cost;
}

int main() {
    fastio;
    
    int N; cin>>N;
    for (int i=0; i<N-1; i++) {
        int a, b; cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    ll min_cost = 999999999999;
    for (int c=1; c<=max_color; c++) {
        min_cost = min(min_cost, dfs(1, c));
    }
    cout<<min_cost<<endl;
}