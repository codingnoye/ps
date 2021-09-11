#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;


void solve() {
    int L, Q; cin>>L>>Q;
    set<int> s1;
    set<int, greater<int>> s2;
    s1.insert(0);
    s1.insert(L);
    s2.insert(0);
    s2.insert(L);
    for (int i=0; i<Q; i++) {
        int c, x; cin>>c>>x;
        if (c == 1) {
            s1.insert(x);
            s2.insert(x);
        } else {
            auto lower = s1.lower_bound(x);
            auto upper = s2.lower_bound(x);
            cout<<(*lower-*upper)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}