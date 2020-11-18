#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int arr[501][501];
int dp[501][501];
int K;
int get(int y, int x) {
    if (dp[y][x] != 0) return dp[y][x];
    dp[y][x] = 1;
    if (0<=y-1) if(arr[y-1][x]>arr[y][x]) dp[y][x] = max(dp[y][x], 1+get(y-1, x));
    if (y+1<K) if(arr[y+1][x]>arr[y][x]) dp[y][x] = max(dp[y][x], 1+get(y+1, x));
    if (0<=x-1) if(arr[y][x-1]>arr[y][x]) dp[y][x] = max(dp[y][x], 1+get(y, x-1));
    if (x+1<K) if(arr[y][x+1]>arr[y][x]) dp[y][x] = max(dp[y][x], 1+get(y, x+1));
    return dp[y][x];
}
void solve() {
    cin>>K;
    for (int y=0; y<K; y++)
        for (int x=0; x<K; x++)
            cin>>arr[y][x];
    int mx = 1;
    for (int y=0; y<K; y++)
        for (int x=0; x<K; x++)
            mx = max(get(y, x), mx);
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}