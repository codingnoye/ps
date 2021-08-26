#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

bool sieve[10000001];
set<ll> gsosu;
void solve() {
    ll res = 0;
    ll A, B; cin>>A>>B;
    for(ll i = 2; i <= 10000000; i++) {
        if(!sieve[i]) {
            for (ll j = i*i; j <= B; j *= i) {
                if (A <= j && j <= B)
                if (gsosu.find(j) == gsosu.end()) {
                    gsosu.insert(j);
                    res++;
                }
                if (j - 1 > B/i) break;
            }
            for(ll j = i*2; j <= 10000000; j += i) {
                sieve[j] = true;
            }
        }
    }
    cout<<res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}