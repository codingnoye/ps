#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[15][1<<14];
const int MOD = 9901;

int MAX;
int N, M;
#define getbit(bf, i) ((bf & (1<<i)) != 0)
#define setbit(bf, i) (bf | (1<<i))

void rec(int y, int cnt, int bf, int i) {
    if (i >= M) {
        dp[y][(~bf) & (MAX-1)] += cnt;
        dp[y][(~bf) & (MAX-1)] %= MOD;
        // cout<<"dp["<<y<<"]["<<bitset<6>((~bf) & (MAX-1))<<"]+="<<cnt<<endl;
        return;
    }
    if (getbit(bf, i)) {
        rec(y, cnt, bf, i+1);
    } else {
        rec(y, cnt, bf, i+1);
        if (i < M-1 && getbit(bf, i+1) == 0) {
            rec(y, cnt, setbit(setbit(bf, i), i+1), i+2);
        }
    }
}

void solve() {
    cin>>N>>M;
    MAX = (1<<M);
    dp[0][0] = 1;
    for (int y=0; y<N; y++) {
        for (int bi=0; bi<MAX; bi++) {
            if (dp[y][bi] == 0) continue;
            rec(y+1, dp[y][bi], bi, 0);
        }
    }
    // for (int y=0; y<=N; y++) {
    //     for (int bi=0; bi<MAX; bi++) {
    //         cout<<dp[y][bi]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dp[N][0]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}