#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef vector<vector<int>> mat;

ll MOD = 1000;
mat operator* (mat& A, mat& B) {
    int N = A.size();
    mat C = mat(N, vector<int> (N, 0));
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
    mat ans = mat(N, vector<int> (N, 0));
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
    ll N, B; cin>>N>>B;
    mat m(N, vector<int> (N, 0));
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>m[y][x];
        }
    }
    mat res = fast_pow(m, B);
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cout<<res[y][x]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}