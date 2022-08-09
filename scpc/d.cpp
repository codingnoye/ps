#include <bits/stdc++.h>
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

vector<int> stob(string s) {
    vector<int> res;
    for (auto c : s) {
        res.push_back(c == 'a');
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        int LX, LY; cin>>LX>>LY;

        string X, Y; cin>>X>>Y;

        vector<int> a_indices;
        vector<int> b_indices;

        for (int i=0; i<LX; i++) {
            if (X[i] == 'a') {
                a_indices.push_back(i);
            }
            if (X[i] == 'b') {
                b_indices.push_back(i);
            }
        }
        auto YYY = stob(Y);

        int a_cnt = 0;
        int b_cnt = 0;
        for (int i=0; i<LY; i++) {
            if (Y[i] == 'a') {
                a_cnt++;
            }
            if (Y[i] == 'b') {
                b_cnt++;
            }
        }

        bool res = false;
        int as = a_indices.size(), bs = b_indices.size();
        for (int is=0; is<as-a_cnt+1; is++) {
            int ie = is + a_cnt;
            for (int js=0; js<bs-b_cnt+1; js++) {
                int isjs = is + js;

                int je = js + b_cnt;

                vector<int> test(LY);

                int i = is;
                int j = js;
                while (i < ie && j < je) {
                    if (a_indices[i] < b_indices[j]) {
                        test[i+j-isjs] = 1;
                        i++;
                    } else {
                        test[i+j-isjs] = 0;
                        j++;
                    }
                    if (test[i+j-1-isjs] != YYY[i+j-1-isjs]) break;
                }
                while (i < ie) {
                    test[i+j-isjs] = 1;
                    i++;
                    if (test[i+j-1-isjs] != YYY[i+j-1-isjs]) break;
                }
                while (j < je) {
                    test[i+j-isjs] = 0;
                    j++;
                    if (test[i+j-1-isjs] != YYY[i+j-1-isjs]) break;
                }

                // cout<<is<<' '<<ie<<' '<<js<<' '<<je<<endl;
                // cout<<btos(test)<<endl;
                if (test == YYY) {
                    res = true;
                    goto end;
                }

            }
        }
    end:
        cout<<"Case #"<<C<<endl<<(res ? "YES" : "NO")<<endl;
    }
}