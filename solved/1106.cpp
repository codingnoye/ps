#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef pair<int, int> pii;
pii city[21];
int dp[1000001] = {0};

void solve() {
    int C, N; cin>>C>>N;
    for (int i=0; i<N; i++) {
        int cost, value; cin>>cost>>value;
        city[i] = make_pair(cost, value);
    }
    for (int i=1; i<=1000001; i++) {
        for (int j=0; j<N; j++) {
            if (i >= city[j].first) {
                dp[i] = max(dp[i], dp[i-city[j].first] + city[j].second);
            }
        }
        if (dp[i] >= C) {
            cout<<i<<endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}