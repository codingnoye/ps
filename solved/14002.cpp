#include <iostream>
#include <vector>
using namespace std;

int nums[1001];
vector<int> dp[1001];
int main() {
    int n, x; cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>x;
        nums[i] = x;
        dp[i].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (nums[i]<nums[j]) {
                int tmp = dp[i].size()+1;
                if (tmp>dp[j].size()) {
                    copy(dp[i].begin(), dp[i].end(), dp[j].begin());
                    dp[j].push_back(nums[j]);
                }
            }
        }
    }
    int mx = 0;
    int mxi = -1;
    for (int i=1; i<=n; i++) {
        if (mx<dp[i].size()) {
            mx = dp[i].size();
            mxi = i;
        }
    }
    cout<<mx<<endl;
    for (auto k=dp[mxi].begin(); k<dp[mxi].end(); k++) {
        cout<<*k<<" ";
    }
    cout<<endl;
}