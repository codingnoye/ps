#include <bits/stdc++.h>
#include <complex>
#define fastio cin.tie(0)->sync_with_stdio(0)
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ull MOD = 998244353;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;
typedef vector<int> vec;

const int mod = MOD;
using lint = long long;
lint ipow(lint x, lint p){
    lint ret = 1, piv = x;
    while(p){
        if(p & 1) ret = ret * piv % mod;
        piv = piv * piv % mod;
        p >>= 1;
    }
    return ret;
}
vec berlekamp_massey(vec x){
    vec ls, cur;
    int lf, ld;
    for(int i=0; i<x.size(); i++){
        lint t = 0;
        for(int j=0; j<cur.size(); j++){
            t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
        }
        if((t - x[i]) % mod == 0) continue;
        if(cur.empty()){
            cur.resize(i+1);
            lf = i;
            ld = (t - x[i]) % mod;
            continue;
        }
        lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
        vec c(i-lf-1);
        c.push_back(k);
        for(auto &j : ls) c.push_back(-j * k % mod);
        if(c.size() < cur.size()) c.resize(cur.size());
        for(int j=0; j<cur.size(); j++){
            c[j] = (c[j] + cur[j]) % mod;
        }
        if(i-lf+(int)ls.size()>=(int)cur.size()){
            tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
        }
        cur = c;
    }
    for(auto &i : cur) i = (i % mod + mod) % mod;
    return cur;
}
int get_nth(vec rec, vec dp, lint n){
    int m = rec.size();
    vec s(m), t(m);
    s[0] = 1;
    if(m != 1) t[1] = 1;
    else t[0] = rec[0];
    auto mul = [&rec](vec v, vec w){
        int m = v.size();
        vec t(2 * m);
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                t[j+k] += 1ll * v[j] * w[k] % mod;
                if(t[j+k] >= mod) t[j+k] -= mod;
            }
        }
        for(int j=2*m-1; j>=m; j--){
            for(int k=1; k<=m; k++){
                t[j-k] += 1ll * t[j] * rec[k-1] % mod;
                if(t[j-k] >= mod) t[j-k] -= mod;
            }
        }
        t.resize(m);
        return t;
    };
    while(n){
        if(n & 1) s = mul(s, t);
        t = mul(t, t);
        n >>= 1;
    }
    lint ret = 0;
    for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
    return ret % mod;
}
int guess_nth_term(vec x, lint n){
    if(n < x.size()) return x[n];
    vec v = berlekamp_massey(x);
    if(v.empty()) return 0;
    return get_nth(v, x, n);
}
ull pow(ull x, ull y) {
    ull res = 1;
    while (y > 0) {
        if (y % 2) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y /= 2;
    }
    return res;
}

ull inv(ull x) {
    return pow(x, MOD-2);
}

ull fermat_div(ull num, ull den) {
    return (num*inv(den))%MOD;
}

vector<ull> dp_fact;
void gen_dpfact() {
    dp_fact.push_back(1);
    for (ull i=1; i<=1000; i++) {
        dp_fact.push_back((dp_fact.back()*i)%MOD);
    }
}

ull fact(ull n) {
    if (n < dp_fact.size()) {
        return dp_fact[n];
    }
    ull res = dp_fact.back();
    for (ull i=dp_fact.size(); i<=n; i++) {
        res = (res*i)%MOD;
    }
    return res;
}

ull multinomial_coefficient(ull k, vector<ull>& arr) {
    ull num = fact(k);
    for (ull i=0; i<arr.size(); i++) {
        ull den = fact(arr[i]);
        num = fermat_div(num, den);
    }
    return num;
}

ull N, K;
ull ans_for_k;
ull ans;
vector<ull> arr;
vector<ull> P;
vector<ull> counts;
ull nowk;
void gen_arr(int left, int idx = 0) {
    // cout<<"gen_arr("<<left<<", "<<idx<<")"<<endl;
    if (idx == arr.size()) {
        if (left != 0) return;
        int num_nonzero = 0;
        // cout<<"{";
        for (ull i=0; i<arr.size(); i++) {
            // cout<<arr[i]<<", ";
            if (arr[i] != 0) {
                num_nonzero++;
            }
        }
        // cout<<"}"<<endl;
        ull coef = multinomial_coefficient(nowk, arr);
        ull res = coef;
        // cout<<"coef: "<<coef<<endl;
        for (int i=0; i<N; i++) {
            res *= pow(P[i], arr[i]);
            res %= MOD;
        }
        counts[num_nonzero] += res;
        counts[num_nonzero] %= MOD;
        return;
    }
    for (int i=left; i>=0; i--) {
        arr[idx] = i;
        gen_arr(left - i, idx+1);
    }
}

int main() {
    fastio;
    gen_dpfact();
    // // N = 3 => A B C
    // // A^2 + B^2 + C^2 + 2AB + 2BC + 2CA
    // cout<<multinomial_coefficient(2, {2,0,0})<<endl; // 1
    // cout<<multinomial_coefficient(2, {1,1,0})<<endl; // 2
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cin>>N>>K;

        P = vector<ull>(N);
        for (int i=0; i<N; i++) {
            cin>>P[i];
        }

        if (N > 10 || K > 50) {
            cout<<"Case #"<<t<<endl<<0<<endl;
            continue;
        }
        // {N, 0, 0, 0} {N-1, 1, 0, 0} {} ...
        ans = 0;

        for (int k=1; k<=K; k++) {
            arr = vector<ull>(N, 0);
            counts = vector<ull>(N+1, 0);
            ans_for_k = 0;
            nowk = k;
            gen_arr(k);
            for (int i=1; i<=N; i++) {
                // cout<<i<<" term count: "<<counts[i]<<endl;
                ans_for_k += counts[i] * i;
                ans_for_k %= MOD;
            }
            ans ^= ans_for_k;
        }
        cout<<"Case #"<<t<<endl<<ans<<endl;
    }
}