#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = 1000000;

int mu[MAX];
void build_mu() {
    mu[1] = 1;
    for(int i = 1; i < MAX; i++) {
        for(int j = 2 * i; j < MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
}

ll sqfree_cnt(ll n) {
    ll cnt = n;
    for(ll i = 1; i * i <= n; i++) {
        cnt -= mu[i] * (n / (i * i));
    }
    return cnt;
}

void solve() {
    ll K; cin>>K;
    build_mu();
	ll left = 0, right = 1000000000001;
  	while(left < right) {
        ll mid = (left + right) / 2;
        if(K <= sqfree_cnt(mid)) {
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