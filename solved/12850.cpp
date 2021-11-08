#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

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

mat m({
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
});
void solve() {
    ll N; cin>>N;
    mat r = fast_pow(m, N);
    cout<<r[0][0]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}