#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[15][2] = {0};
int dp[15];
int N;

int dfs(int now) {
    if (now>=N) return 0;
    if (dp[now]==-1) dp[now] = max(dfs(now+1), ((now+arr[now][0]<=N)?(arr[now][1]+dfs(now+arr[now][0])):0));
    return dp[now];
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i][0]>>arr[i][1];
        dp[i] = -1;
    }
    cout<<dfs(0)<<endl;
}