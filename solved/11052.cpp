#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = {0};
int dp[1001] = {0};

int main() {
    int N; cin>>N;
    for (int i=1; i<=N; i++) cin>>arr[i];
    dp[0] = 0;
    for (int i=1; i<=N; i++) {
        dp[i] = 0;
        for (int j=0; j<i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[i-j]);
        }
    }
    cout<<dp[N]<<endl;
}