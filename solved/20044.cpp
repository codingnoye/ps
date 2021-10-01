#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int n, m, ans = 0xfffffff;
    vector<int> arr;

    cin >> n;
    for(int i = 0; i < n * 2; i++) {
        cin >> m;
        arr.push_back(m);
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        ans = min(ans, arr[n + i] + arr[n - i - 1]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}