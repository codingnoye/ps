#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

void solve() {
    int T; cin>>T;
    while (T--) {
        int sx, sy, dx, dy; cin>>sx>>sy>>dx>>dy;
        int n; cin>>n;
        int res = 0;
        for (int i=0; i<n; i++) {
            int x, y, r; cin>>x>>y>>r;
            bool incS = (x-sx)*(x-sx)+(y-sy)*(y-sy)<r*r;
            bool incD = (x-dx)*(x-dx)+(y-dy)*(y-dy)<r*r;
            if (incS != incD) res++;
        }
        cout<<res<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}