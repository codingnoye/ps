#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 2001;
int cache[MAXN][MAXN];
int nCr(int n, int r, int MOD) {
    if(cache[n][r] != -1)
        return cache[n][r];
    if(r==0 || r==n)
        return cache[n][r] = 1;
    return cache[n][r] = (nCr(n-1, r-1, MOD)+nCr(n-1, r, MOD)%MOD);
}

vector<int> get_digits(ll n, int p) {
    vector<int> res;
    while(n){
        res.push_back(n%p);
        n /= p;
    }
    return res;
}

ll lucas(ll n, ll r, ll MOD) {
    vector<int> ns = get_digits(n, MOD);
    vector<int> rs = get_digits(r, MOD);
    ll ret = 1;
    for(int i = 0 ; i < max(ns.size(), rs.size()); i++){
        ll nn = (i < ns.size()) ? ns[i] : 0;
        ll rr = (i < rs.size()) ? rs[i] : 0;
        if(nn < rr)
            return 0;
        ret = ret * nCr(nn, rr, MOD);
        ret %= MOD;
    }
    return ret;
}

int main() {
    fastio;
    memset(cache, -1, sizeof(cache));
    ll N, R, MOD; cin>>N>>R>>MOD;
    cout<<lucas(N, R, MOD)<<endl;
}