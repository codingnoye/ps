#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int N;
int dp[1000001][2];
unordered_map<int, vector<int>> childs;

int recc(int node, bool parentEarly, int parent) {
    if (dp[node][true] == -1) {
        int res1 = 1;
        int res2 = 0;
        for (int child: childs[node]) {
            if (child == parent) continue;
            res1 += recc(child, true, node);
            res2 += recc(child, false, node);
        }
        dp[node][true] = res1;
        dp[node][false] = res2;
    }

    if (parentEarly) {
        if (dp[node][true] < dp[node][false])
            return dp[node][true];
        else
            return dp[node][false];
    } else {
        return dp[node][true];
    }
}

void solve() {
    cin>>N;
    fill(&dp[0][0], &dp[N][2], -1);
    for (int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        childs[u].push_back(v);
        childs[v].push_back(u);
    }
    cout<<recc(1, true, 0)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}