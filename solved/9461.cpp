#include <iostream>
using namespace std;

long dp[101] = {0, 1, 1, 1, 2, 2};
int main() {
    int T, x; cin>>T;
    for (int i=6; i<=100; i++) {
        dp[i] = dp[i-5]+dp[i-1];
    }
    while (T--) {
        cin>>x;
        cout<<dp[x]<<endl;
    }
}