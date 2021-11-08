#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// #define endl '\n'
typedef unsigned long long ll;

ll fast_pow(ll b, ll e, ll m){
    ll ans = 1;
    while (e) {
        if (e % 2 == 1) {
            ans *= b;
            ans %= m;
        }
        b = b * b % m;
        e /= 2;
    }
    return ans;
}

bool miller(ll n, ll a) {
    if (a % n == 0) return true;
    ll k = n-1;
    while (true) {
        ll tmp = fast_pow(a, k, n);
        if (tmp == n-1) return true;
        if (k % 2) return (tmp == 1 || tmp == n-1);
        k>>=1;
    }
}

vector<int> primes({2, 7, 61});
// for ll, 
// vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});
bool is_prime(ll n) {
    for (int prime: primes) {
        if (miller(n, prime) == false)
            return false;
    }
    return true;
}

void solve() {
    int N; cin>>N;
    int res = 0;
    while (N--) {
        ll n; cin>>n;
        ll a = 2*n+1;
        if (a<9) {
            res++;
        } else if (is_prime(a) == true) {
            res++;
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}