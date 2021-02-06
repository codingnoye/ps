#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[200000];
int dp[200000];
int MOD = 1000000007;
int main() {
    int N; cin>>N;
    for (int i=0; i<N; i++) cin>>arr[i];
    dp[N-1] = arr[N-1];
    for (int i=N-2; i>=0; i--) {
        dp[i] = (dp[i+1] + arr[i]) % MOD;
    }
    long long SUM = 0;
    for (int i=0; i<N-1; i++) {
        SUM += arr[i]*dp[i+1];
        SUM %= MOD;
    }
    cout<<SUM<<endl;
}