#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

ll pow2[55];

ll f(ll x) {
    return (x+1)*pow2[x+1]-1;
}

void solve() {
    ll now = 1;
    for (int i=0; i<55; i++) {
        pow2[i] = now;
        now<<=1;
    }

    ll N; cin>>N;

    int left = 0; int right = 55;
    while(left < right) {
        int mid = (left + right) / 2;
        if (N <= f(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout<<left<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}