#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    bool check = false;
    int a, b, n, w;
    pair<int, int> ans;
    cin >> a >> b >> n >> w;
    for(int i = 1; i < n; i++) {
        int x = i, y = n - i;
        if(a * x + b * y == w) {
            if(!check) {
                check = true;
                ans = {x, y};
            }
            else {
                check = false;
                break;
            }
        }
    }
    if(!check)
        cout << -1 << endl;
    else
        cout << ans.first << " " << ans.second << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}