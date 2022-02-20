#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = (1<<10)-1;
const int MOD = 1000000000;
int dp[101][10][MAX+1]; // n, last, bf

void solve() {
    for (int i=0; i<=9; i++) {
        int bi = 1<<i;
        dp[1][i][bi] = 1;
    }

    int N; cin>>N;
    for (int n=1; n<N; n++) {
        for (int i=0; i<10; i++) {
            for (int bf=1; bf<=MAX; bf++) {
                if (i>0) {
                    dp[n+1][i-1][bf | (1<<(i-1))] += dp[n][i][bf];
                    dp[n+1][i-1][bf | (1<<(i-1))] %= MOD;
                }
                if (i<9) {
                    dp[n+1][i+1][bf | (1<<(i+1))] += dp[n][i][bf];
                    dp[n+1][i+1][bf | (1<<(i+1))] %= MOD;
                }
            }
        }
    }
    int res = 0;
    for (int i=1; i<10; i++) {
        res += dp[N][i][MAX];
        res %= MOD;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}