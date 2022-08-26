#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef vector<ll> row;
typedef vector<vector<ll>> mat;

ll MOD = 1000000007;
mat operator* (mat& A, mat& B) {
    int N = A.size();
    mat C = mat(N, vector<ll> (N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

mat fast_pow(mat b, ll e){
    int N = b.size();
    mat ans = mat(N, vector<ll> (N, 0));
    for (int i=0; i<N; i++) {
        ans[i][i] = 1;
    }

    while (e) {
        if (e % 2 == 1) {
            ans = ans * b;
        }
        b = b * b;
        e /= 2;
    }
    return ans;
}

int main() {
    fastio;
    
    int N, M; cin>>N>>M;

    mat route_02(M, row(M));
    mat route_01(M, row(M));
    mat route_12(M, row(M));

    for (int from=0; from<M; from++) {
        for (int to=0; to<M; to++) {
            if (from == to+1 || from == to-1 || from == to)
                route_01[from][to] += 1;
        }
    }
    for (int from=0; from<M; from++) {
        for (int to=0; to<M; to++) {
            if (from == to+1 || from == to-1)
                route_12[from][to] += 1;
        }
    }
    route_02 = route_01 * route_12;

    // for (int y=0; y<M; y++) {
    //     for (int x=0; x<M; x++) {
    //         cout<<route_02[y][x]<<' ';
    //     }
    //     cout<<endl;
    // }

    mat tmp = fast_pow(route_02, (N+1)/2 - 1);
    if (N%2 == 0) tmp = tmp * route_12;

    ll res = 0;
    for (int y=0; y<M; y++) {
        for (int x=0; x<M; x++) {
            res += tmp[y][x];
            res %= MOD;
        }
    }
    cout<<res<<endl;
}