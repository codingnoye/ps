#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;
int mabs (int x) {
    if (x<0) return -x;
    return x;
}
void solve() {
    int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
    int y = mabs(r2-r1);
    int x = mabs(c2-c1);
    int move = 0;
    if (x==0 && y==0) {
        cout<<0<<endl;
        return;
    }
    if (x+y <= 3) {
        cout<<1<<endl;
        return;
    }
    if (x==y) {
        cout<<1<<endl;
        return;
    }
    if (mabs(x-y) <= 3) {
        cout<<2<<endl;
        return;
    }
    if (x<y) swap(x, y);
    int d = x-y;
    y += 2*d;
    if ((x+y)%2 == 0) {
        cout<<2<<endl;
        return;
    }
    cout<<3<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}