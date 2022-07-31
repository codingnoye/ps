#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef unsigned long long ull;
typedef __int128 llll;

ll big_mul(ll x, ll y, ll mod) {
    return (llll)x * y % mod;
}

ll fast_pow(ll b, ll e, ll m){
    ll ans = 1;
    while (e) {
        if (e % 2 == 1) {
            ans = big_mul(ans, b, m);
        }
        b = big_mul(b, b, m);
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

vector<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});
bool is_prime(ll n) {
    for (int prime: primes) {
        if (n == prime) return true;
        if (n>40 && miller(n, prime) == false) return false;
    }
    if (n<=40) return false;
    return true;
}

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

void rec(ll n, vector<ll>& v) {
    if (n == 1) return;
    if (n % 2 == 0) {
        v.push_back(2);
        rec(n / 2, v);
        return;
    }
    if (is_prime(n)) {
        v.push_back(n);
        return;
    }
    ll a, b, c, g = n;

    // 수열 생성 함수
    auto f = [&](ll x) {
        return (c + big_mul(x, x, n)) % n;
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
    rec(g, v);
    rec(n / g, v);
}

map<ll, ll> factorize(ll n) {
    vector<ll> ret;
    rec(n, ret);
    map<ll, ll> res;
    for (ll x: ret) {
        if (res.find(x) != res.end()) {
            res[x]++;
        } else {
            res[x] = 1;
        }
    }
    return res;
}

int main() {
    fastio;

    ll N; cin>>N;
    map<ll, ll> factors = factorize(N);
    // for (auto& [v, cnt]: factors) {
    //     cout<<v<<" "<<cnt<<endl;
    // }

    bool valid;
    // case 1
    valid = true;
    for (auto& [v, cnt]: factors) {
        if (cnt % 2 != 0) {
            valid = false;
            break;
        }
    }
    if (valid) {
        cout<<1<<endl;
        return 0;
    }

    // case 2
    valid = true;
    for (auto& [v, cnt]: factors) {
        if (v%4 == 3 && cnt % 2 != 0) {
            valid = false;
            break;
        }
    }
    if (valid) {
        cout<<2<<endl;
        return 0;
    }

    // case 3
    while (N%4 == 0) {
        N /= 4;
    }
    if (N%8 == 7) {
        cout<<4<<endl;
        return 0;
    }

    // case 4
    cout<<3<<endl;
}