#include <iostream>
using namespace std;

int dp[1000001];
int main() {
    int N; cin>>N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<1000001; i++) {
        dp[i] = (dp[i-2]+dp[i-1])%15746;
    }
    cout<<dp[N]<<endl;
}