#include <iostream>
using namespace std;

int dp[2][100002] = {0};
int main() {
    int T; cin>>T;
    for (int t=0; t<T; t++) {
        int n; cin>>n;
        for (int j=0; j<2; j++) {
            for (int i=0; i<n; i++) {
                cin>>dp[j][i];
            }
        }
        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        for (int i=2; i<n; i++) {
            for (int j=0; j<2; j++) {
                int a = dp[0][i-2];
                int b = dp[1][i-2];
                int c = dp[(j+1)%2][i-1];
                dp[j][i] += (a>b)?(a>c?a:c):(b>c?b:c);
            }
        }
        int a = dp[0][n-1];
        int b = dp[1][n-1];
        cout<<(a>b?a:b)<<endl;
    }
}