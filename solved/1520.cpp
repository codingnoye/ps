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

int arr[501][501];
int dp[501][501];
int M, N;

int get(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    if (0<=y-1) if (arr[y][x] < arr[y-1][x]) dp[y][x] += get(y-1, x);
    if (y+1<M) if (arr[y][x] < arr[y+1][x]) dp[y][x] += get(y+1, x);
    if (0<=x-1) if (arr[y][x] < arr[y][x-1]) dp[y][x] += get(y, x-1);
    if (x+1<N) if (arr[y][x] < arr[y][x+1]) dp[y][x] += get(y, x+1);
    return dp[y][x];
}

void solve() {
    cin>>M>>N;
    for (int y=0; y<M; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
            dp[y][x] = -1;
        }
    }
    dp[0][0] = 1;
    cout<<get(M-1, N-1)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}