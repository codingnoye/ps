#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t lll;

lll fast_pow(lll b, lll e, lll m){
    lll ans = 1;
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

pair<lll, pair<lll, lll>> xGCD(lll a, lll b) {    // it returns {g, {x,y}}, ax+by=g
    if(b == 0) return {a,{1,0}};
    pair<lll,pair<lll,lll>> ret = xGCD(b, a%b);
    lll g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

lll modinv(lll a, lll mod) {
    auto res = xGCD(a,mod);
    if(res.first > 1) return -1;
    return (res.second.first + mod) % mod;
}

lll modulo(lll a, lll b, lll mod) {
	lll sum = 1;

	while (b) {
		if (b % 2) sum = sum * a % mod;
		a = a * a % mod;
		b /= 2;
	}

	return sum;
}

lll go(lll x, lll r, lll mod) {
    if (x<0) return 0;
	if (!x) return 1;
	if (x == 1) return (r + 1) % mod;
	if (x % 2) return go(x / 2, r, mod) * (1 + modulo(r, x / 2 + 1, mod)) % mod;
	return (go(x / 2 - 1, r, mod) * (1 + modulo(r, x / 2, mod)) % mod + modulo(r, x, mod) % mod) % mod;
}

void solve() {
    ull m, a, c, X, n, g; cin>>m>>a>>c>>X>>n>>g;
    a %= m;
    X %= m;

    // a^n * X
    lll left = fast_pow(a, n, m);
    left = left * X;
    left %= m;
    // c*(a 등비수열)
    lll right = go(((lll)n)-1, a, m) * c;
    right %= m;
    lll res = left + right;
    res %= m;
    cout<<(ll)(res%g)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}