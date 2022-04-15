#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef vector<vector<ll>> mat;

ll MOD = 1000003;
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

void solve() {
    ll N, S, E, T; cin>>N>>S>>E>>T;
    mat m = mat(50, vector<ll> (50, 0));
    for (int i=0; i<10; i++) {
        for (int j=1; j<5; j++) {
            m[j*10+i][(j-1)*10+i] = 1;
        }
    }
    // for (int i=0; i<50; i++) {
    //     for (int j=0; j<50; j++) {
    //         cout<<m[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for (int i=0; i<N; i++) {
        string tmp; cin>>tmp;
        for (int j=0; j<N; j++) {
            int n = tmp.at(j) - '0';
            if (n==0) continue;
            m[i][(n-1)*10+j] = 1;
        }
    }
    mat ans = fast_pow(m, T);
    cout<<ans[S-1][E-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}