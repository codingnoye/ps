#include <bits/stdc++.h>
<<<<<<< HEAD
#include <complex>
#define fastio cin.tie(0)->sync_with_stdio(0)
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ull MOD = 998244353;
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

const int DP_FACT_SIZE = 5000000;
int dp_fact[DP_FACT_SIZE];
int dp_invfact[DP_FACT_SIZE];
void gen_dpfact() {
    dp_fact[0] = 1;
    for (ull i=1; i<DP_FACT_SIZE; i++) {
        dp_fact[i]=(dp_fact[i-1]*i)%MOD;
    }
    dp_invfact[DP_FACT_SIZE-1] = inv(dp_fact[DP_FACT_SIZE-1]);
    for (ll i=DP_FACT_SIZE-2; i>=0; i--) {
        dp_invfact[i] = (dp_invfact[i+1]*(i+1))%MOD;
    }
}

ull fact(ull n) {
    if (n < DP_FACT_SIZE) {
        return dp_fact[n];
    }
    ull res = dp_fact[DP_FACT_SIZE-1];
    cout<<"not hit"<<endl;
    for (ull i=DP_FACT_SIZE; i<=n; i++) {
        res = (res*i)%MOD;
    }
    return res;
}

ull multinomial_coefficient(ull k, vector<ull>& arr) {
    ull num = fact(k);
    for (ull i=0; i<arr.size(); i++) {
        num *= dp_invfact[arr[i]];
        num %= MOD;
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
    // coutr<<multinomial_coefficient(2, {2,0,0})<<endl; // 1
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
=======
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        ll ans = 0;

        // code here

        cout<<"Case #"<<C<<endl<<ans<<endl;
>>>>>>> 2d8c2d02d42975dbb79638bed5e25557b3f26cd5
    }
}