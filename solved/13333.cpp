#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int n;
    vector<int> nums(1001, 0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> nums[i];
    
    for(int k = 0; k <= n; k++) {
        int upper = 0, lower = 0;
        for(int i = 1; i <= n; i++) {
            if(nums[i] >= k) upper++;
            else if(nums[i] <= k) lower++;
        }
        if(upper == k && lower == n - k) {
            cout << k << endl;
            return;
        }
        lower = 0; upper = 0;
        for(int i = 1; i <= n; i++) {
            if(nums[i] <= k) lower++;
            else if(nums[i] >= k) upper++;
        }
        if(upper == k && lower == n - k) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}