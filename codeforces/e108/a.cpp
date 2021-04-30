#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

void solve() {
    int T; cin>>T;
    while (T--) {
        int a, b, c; cin>>a>>b>>c;
        if (a>b) swap(a, b);
        if (((b+a-1)/a) <= c+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}