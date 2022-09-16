#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, K, B; cin>>N>>K>>B;
    vector<int> A(B+2);
    for (int i=0; i<B; i++) cin>>A[i];
    A[B] = 0;
    A[B+1] = N+1;
    sort(A.begin(), A.end());

    int j = 1;
    int res = 99999999;
    for (int i = 0; i < B+2; i++) {
        while (A[j] - A[i] - 1 < K) {
            j++;
            if (j >= B+2) break;
        }
        if (j >= B+2) break;

        res = min(j - i - 1, res);
    }
    cout<<res<<endl;
}