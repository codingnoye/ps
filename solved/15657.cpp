#include <iostream>
#include <algorithm>
using namespace std;
int history[9] = {0};
int n, m;
int nums[9];
void solve(int now, int last) {
    if (now>m) {
        for (int j=1; j<=m; j++) cout<<nums[history[j]]<<" ";
        cout<<'\n';
        return;
    }
    for (int i=last; i<=n; i++) {
        history[now] = i;
        solve(now+1, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>nums[i];
    }
    sort(nums+1, nums+n+1);
    solve(1, 1);
}