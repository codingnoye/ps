#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef __int128 i128;

ll mul(ll x, ll y, ll mod) {
    return (i128)x * y % mod;
}

ll fast_pow(ll b, ll e, ll m){
    ll ans = 1;
    while (e) {
        if (e % 2 == 1) {
            ans = mul(ans, b, m);
        }
        b = mul(b, b, m);
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

//vector<int> primes({2, 7, 61});
// for ll, 
vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});
bool is_prime(ll n) {
    for (int prime: primes) {
        if (n == prime) return true;
        if (n>40 && miller(n, prime) == false) return false;
    }
    if (n<=40) return false;
    return true;
}

ull gcd(ull a, ull b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

vector<ll> factors;
void factorize(ll n) {
    if (n == 1) return;
    if (n % 2 == 0) {
        factors.push_back(2);
        factorize(n / 2);
        return;
    }
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    ll a, b, c, g = n;
    auto f = [&](ll x) {
        return (c + mul(x, x, n)) % n;
    };
    do {
        if (g == n) {
            a = b = rand() % (n - 2) + 2;
            c = rand() % 20 + 1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs(a - b), n);
    } while (g == 1);
    factorize(g);
    factorize(n / g);
}


void solve() {
    ll N; cin>>N;
    factorize(N);
    sort(factors.begin(), factors.end());
    for (int fac: factors) {
        cout<<fac<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}