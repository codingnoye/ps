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

int dp[100001];

void solve() {
    int N; cin>>N;
    vector<int> v;
    int i=1;
    while (true) {
        int s = i*i;
        if (s>N) break;
        v.push_back(s);
        i++;
    }

    for (int i=1; i<=N; i++) {
        dp[i] = 99999999;
        for (auto it=v.begin(); it<v.end(); it++) {
            if (i < *it) break;
            dp[i] = min(dp[i], dp[i-(*it)]+1);
        }
    }
    cout<<dp[N]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}