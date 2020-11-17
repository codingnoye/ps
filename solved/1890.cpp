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

int arr[101][101];
long dp[101][101];
void solve() {
    int N; cin>>N;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    dp[0][0] = 1;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            int now = arr[y][x];
            if (now==0) continue;
            if (y+now < N) dp[y+now][x] += dp[y][x];
            if (x+now < N) dp[y][x+now] += dp[y][x];
        }
    }
    cout<<dp[N-1][N-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}