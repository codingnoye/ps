#include <iostream>
using namespace std;

int nums[1001];
int dp[1001] = {0};
int main() {
    int n; cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>nums[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (nums[i]>nums[j]) {
                int tmp = dp[i]+1;
                dp[j] = tmp>dp[j]?tmp:dp[j];
            }
        }
    }
    int mx = 0;
    for (int i=1; i<=n; i++) {
        if (mx<dp[i]) {
            mx = dp[i];
        }
    }
    cout<<(mx+1)<<endl;
}