#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ull, ull> puu;
typedef pair<ll, ll> pll;


void solve() {
    int sx, sy, gx, gy; cin>>sx>>sy>>gx>>gy;
    sy = -sy;
    int dx = gx - sx;
    int dy = gy - sy;
    long double m = (long double)dy/dx;
    cout<<fixed;
    cout.precision(16);
    cout<<((long double)sx - (long double)sy/m)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}