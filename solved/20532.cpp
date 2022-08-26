#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

ll ans = 0;
vector<ll> cnts(100001), cnts_factor(100001), cnts_same(100001);
vector<vector<int>> G;
vector<int> A;
void dfs(int node) {
    int a = A[node];
    // cout<<node<<' '<<a<<endl;

    // a를 약수로 가지는 수들
    ans += cnts_factor[a];

    // a의 약수를 기록하면서, 이미 나온 a의 약수 세기
    int sqrta = round(sqrt(a));
    for (int n=1; n<=sqrta; n++) {
        if (a % n == 0) {
            int m = a/n;
            cnts_factor[n]++;
            ans += cnts[n];
            if (n!=m) {
                cnts_factor[m]++;
                ans += cnts[m];
            }
        }
    }
    ++cnts[a];

    for (int ch: G[node]) {
        dfs(ch);
    }

    for (int n=1; n<=sqrta; n++) {
        if (a % n == 0) {
            int m = a/n;
            cnts_factor[n]--;
            if (n!=m)
                cnts_factor[m]--;
        }
    }
    --cnts[a];
}

void dfs_same(int node) {
    int a = A[node];
    ans -= cnts_same[a];

    cnts_same[a]++;

    for (int ch: G[node]) {
        dfs_same(ch);
    }

    cnts_same[a]--;
}

int main() {
    fastio;
    
    int N; cin>>N;
    A = vector<int> (N+1);
    G = vector<vector<int>> (N+1);
    for (int i=1; i<=N; i++) cin>>A[i];
    for (int i=2; i<=N; i++) {
        int p; cin>>p;
        G[p].push_back(i);
    }
    dfs(1);
    dfs_same(1);
    cout<<ans<<endl;
}