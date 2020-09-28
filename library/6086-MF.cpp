#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
const int INF = 2000000002;
const int MAX = 53;
int cap[MAX][MAX] = {0};
int flow[MAX][MAX] = {0};
int from[MAX] = {0};
vector<int> graph[MAX];

void solve() {
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        char A, B; int c; cin>>A>>B>>c;
        int a, b;
        a = (A<='Z'?A-'A':26+A-'a')+1;
        b = (B<='Z'?B-'A':26+B-'a')+1;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cap[a][b] += c;
        cap[b][a] += c;
    }
    int res = 0;
    while (true) {
        for (int i=0; i<MAX; i++) from[i] = 0;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (auto it=graph[now].begin(); it!=graph[now].end(); it++) {
                int to = *it;
                if (flow[now][to] < cap[now][to] && from[to] == 0) {
                    Q.push(to);
                    from[to] = now;
                    if (to=='Z'-'A'+1) break;
                }
            }
        }
        if (from['Z'-'A'+1] == 0) break; // 더이상 우물로 갈 수 없는 경우
        int mn = INF;
        for (int now = 'Z'-'A'+1; now!=1; now=from[now]) {
            mn = min(mn, cap[from[now]][now]-flow[from[now]][now]);
        }
        for (int now = 'Z'-'A'+1; now!=1; now=from[now]) {
            flow[from[now]][now] += mn;
            flow[now][from[now]] -= mn;
        }
        res += mn;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}