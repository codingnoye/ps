#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
// #define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> graph; // vec<vec<dest, label>>

int N, M, K;

const int ERR_INFCYCLE = 1999999;
const int MAX_N = 100001;
// len 자체를 들고 가서, visited가 2 이상일때 len이 늘었는지 비교 -> INF와 CYCLE

int visiting[MAX_N][3];
int last_len[MAX_N][3];
int last_cost[MAX_N][3];
bool dead_end[MAX_N][3];
bool has_dp[MAX_N][3][3];
int dp[MAX_N][3][3]; // idx, label, cost
int dfs_maxlen(int i, int left_cost, int last_label, int nowlen) {
    // cout<<"dfs("<<i<<", "<<left_cost<<", "<<last_label<<", "<<nowlen<<")"<<endl;
    if (last_label != -1) {
        if (dead_end[i][last_label]) {
            return ERR_INFCYCLE;
        }
        if (has_dp[i][last_label][left_cost] && K != -1) {
            return dp[i][last_label][left_cost];
        }
        if (visiting[i][last_label] >= 2) {
            if (last_len[i][last_label] == nowlen) { // 더 탐색하는게 무의미한 사이클
                return 0;
            } else if (last_len[i][last_label] < nowlen && last_cost[i][last_label] == left_cost) { // cost를 소모하지 않고 값이 늘어나는 사이클
                dead_end[i][last_label] = true;
                return ERR_INFCYCLE;
            }
        }
        visiting[i][last_label]++;
        last_len[i][last_label] = nowlen;
        last_cost[i][last_label] = left_cost;
    }

    int max_length = 0;
    for (auto& [j, label] : graph[i]) {
        if (last_label == -1 || (last_label+1)%3 == label) {
            max_length = max(max_length, dfs_maxlen(j, left_cost, label, nowlen+1) + 1);
        } else if (last_label != -1) {
            if (K==-1) {
                max_length = max(max_length, dfs_maxlen(j, left_cost, last_label, nowlen));
            } else if (left_cost > 0) {
                max_length = max(max_length, dfs_maxlen(j, left_cost-1, last_label, nowlen));
            }
        }
        if (max_length >= ERR_INFCYCLE) break;
    }
    
    if (last_label != -1) {
        visiting[i][last_label]--;
        if (max_length >= ERR_INFCYCLE) {
            dead_end[i][last_label] = true;
        }
        has_dp[i][last_label][left_cost] = true;
        dp[i][last_label][left_cost] = max_length;
    }
    return max_length;
}

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int ans = 0;
        cin>>N>>M>>K;

        graph = vector<vector<pair<int, int>>>(N);
        for (int i=0; i<M; i++) {
            int u, v; string label; cin>>u>>v>>label;
            graph[u-1].push_back({v-1, label.at(0)-'A'});
        }

        memset(visiting, 0, sizeof(visiting));
        memset(dead_end, 0, sizeof(dead_end));
        memset(has_dp, 0, sizeof(has_dp));
        memset(dp, 0, sizeof(dp));
        int max_length = 0;
        for (int i=0; i<N; i++) {
            int res = dfs_maxlen(i, max(K, 0), -1, 0);
            max_length = max(max_length, res);
            if (max_length >= ERR_INFCYCLE) break;
        }
        ans = max_length;
        if (ans >= ERR_INFCYCLE) ans = -1;

        cout<<"Case #"<<t<<'\n'<<ans<<endl;
    }
}