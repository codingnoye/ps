#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
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

int main() {
    fastio;
    
    int N; cin>>N;
    while (N--) {
        string s; cin>>s;

        mat forcopy = mat(2, vector<ll> (2, 0));
        forcopy[0][1] = 3;
        forcopy[1][0] = 2;
        forcopy[1][1] = 1;

        mat idm = mat(2, vector<ll> (2, 0));
        idm[0][0] = 1;
        idm[1][1] = 1;

        mat left = mat(idm);
        mat right = mat(idm);
        ll cnt = 0;
        int len = 0;
        for (int i=0; i<(s.size()/2); i++) {
            int li = i;
            int ri = s.size()-1-i;

            int lv = (s.at(li) - 'a');
            int rv = (s.at(ri) - 'a');
            mat lm = mat(forcopy);
            lm[0][0] = lv;
            mat rm = mat(forcopy);
            rm[0][0] = rv;
            left = left * lm;
            right = rm * right;

            len++;

            if (right == left) {
                bool allsame = true;
                for (int j=0; j<=len-1; j++) {
                    if (s.at(li-len+1+j) != s.at(ri+j)) {
                        allsame = false;
                        break;
                    }
                }
                if (!allsame) continue;
                // for (int j=li-len+1; j<=li; j++) cout<<s.at(j);
                // cout<<" == "; 
                // for (int j=ri; j<=ri+len-1; j++) cout<<s.at(j);
                // cout<<endl; 

                cnt+=2;
                left = mat(idm);
                right = mat(idm);
                len = 0;
            }
        }
        if (s.size()&1 || len>0) cnt++;
        cout<<cnt<<endl;
    }
}