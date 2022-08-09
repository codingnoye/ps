#include <bits/stdc++.h>
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

typedef unsigned long long ull;

const ll MOD = 1000000007;

ull mul(ull x, ull y) {
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

bool same_sign(ll x, ll y) {
    return (x > 0) == (y > 0);
}

ll binomial_coefficient(ull n, ull k) {
    ull son = 1; // N!/(N-k)!
    ull mom = 1;
    for (ull i=n-k+1; i<=n; i++) {
        son *= i;
        son %= MOD;
    }
    for (ull i=1; i<=k; i++) {
        mom *= i;
        mom %= MOD;
    }
    return (ll)((son*mul(mom, MOD-2))%MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        ll ans = 0;

        ll N, K; cin>>N>>K;
        
        vector<ll> accsum(N+1);
        ff(i, 0, N) {
            ll x; cin>>x;
            accsum[i+1] = accsum[i] + x;
            // query: [a, b) = accsum[b] - accsum[a]
        }

        ll totalsum = accsum[N];
        ll bucketval = totalsum / K;

        if (totalsum % K != 0) {
            cout<<"Case #"<<C<<endl<<"0"<<endl;
            continue;
        }

        vector<ll> compressed;

        vector<vector<ll>> val_to_indices(K+1);

        if (bucketval != 0) {
            ff(i, 0, N) {
                ll dv = accsum[i+1] / bucketval, md = accsum[i+1] % bucketval;
                if (md == 0 && same_sign(accsum[i+1], bucketval) && dv <= K && dv >= 1 && !(dv == K && i+1 != N)) {
                    compressed.push_back(dv);
                    val_to_indices[dv].push_back(compressed.size()-1);
                }
            }
            vector<ll> dp = vector<ll>(compressed.size(), 0);

            // for (auto x: compressed) {
            //     cout<<x<<" ";
            // }

            // for (auto x: val_to_indices) {
            //     cout<<endl;
            //     for (auto y: x) {
            //         cout<<y<<" ";
            //     }
            // }

            for (int i=0; i<compressed.size(); i++) {
                ll x = compressed[i];
                if (x == 1) {
                    dp[i] = 1;
                    continue;
                }
                for (auto j: val_to_indices[x-1]) {
                    if (j < i) {
                        dp[i] += dp[j];
                        dp[i] %= MOD;
                    }
                }
            }

            cout<<"Case #"<<C<<endl<<dp[dp.size()-1]<<endl;
        } else {
            ll zerocnt = 0;
            ff(i, 0, N) {
                if (accsum[i+1] == 0) zerocnt++;
            }
            // must select last bucket
            // then C(zerocnt-1, k-1)
            // cout<<zerocnt<<' '<<K<<endl;
            
            ll ans;
            
            if (zerocnt-1 < 0 || K-1 < 0) {
                ans = 0;
            } else if (K-1 == 0) {
                ans = 1;
            } else if (zerocnt-1 == 0) {
                ans = 0;
            } else {
                ans = binomial_coefficient(zerocnt-1, K-1);
            }

            cout<<"Case #"<<C<<endl<<ans<<endl;
        }
    }
}