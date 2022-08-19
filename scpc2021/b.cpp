#include <bits/stdc++.h>
<<<<<<< HEAD
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int S = 1<<19;
// 담을 수 있는 원소의 개수 이상인 2^n인 수
// 1<<17 = 2^17 = 131072
// 1<<20 = 2^20 = 1048576

ll tree[2*S];
ll* leaf = tree+S;
// 모든 노드
// 리프 노드는 tree[S+i], i = [0, S) = leaf[i]
// 1이 루트

// 초기화
void init(int n, bool clear = true) { // 최적화가 필요할 때, 값을 수동으로 넣은 후 clear = false
    if (clear) {
        for (int i=S; i<S+n; i++) {
            tree[i] = 1; // 변경할 부분 (기본값)
        }
        for (int i=S+n; i<2*S; i++) {
            tree[i] = 0; // 변경할 부분 (기본값)
        }
    }
    for (int i=S-1; i>=1; i--)  {
        tree[i] = tree[i*2] + tree[i*2+1]; // 변경할 부분 (연산)
    }
}

// 업데이트
void update(int x, ll v) {
    int now = S+x;
    tree[now] = v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = tree[now*2] + tree[now*2+1]; // 변경할 부분 (연산)
    }
}

// 구간 [s, e)에 대한 쿼리
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0; // 변경할 부분 (기본값)
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end); // 변경할 부분 (연산)
    }
}

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        init(N);
        vector<int> A(N);
        vector<vector<int>> indices(N+1); // 반번호 -> vec<위치>

        for (int i=0; i<N; i++) {
            cin>>A[i];
            indices[A[i]].push_back(i);
        }
        for (int i=1; i<=N; i++) {
            sort(indices[i].begin(), indices[i].end());
        }
        ll res = 0;
        for (int left_idx=0; left_idx<N; left_idx++) {
            int val = A[left_idx];
            int right_idx = indices[val].back();
            indices[val].pop_back();
            res += query(left_idx, right_idx);
            update(right_idx, 0);
        }
        cout<<"Case #"<<t<<endl<<res<<endl;
=======
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
>>>>>>> 2d8c2d02d42975dbb79638bed5e25557b3f26cd5
    }
}