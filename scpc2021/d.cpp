<<<<<<< HEAD
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long ll;

int A[258][258];
int DPMIN[258][258];
int DPMAX[258][258];

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        
        for (int y=1; y<=N; y++) {
            for (int x=1; x<=N; x++) {
                cin>>A[y][x];
            }
        }

        int res = 0;
        for (int starty=1; starty<=N; starty++) {
            for (int startx=1; startx<=N; startx++) {
                for (int i=1; i<=N; i++) {
                    DPMIN[i][startx-1] = 999999;
                    DPMAX[i][startx-1] = 0;
                    DPMIN[starty-1][i] = 999999;
                    DPMAX[starty-1][i] = 0;
                }
                for (int y=starty; y<=N; y++) {
                    for (int x=startx; x<=N; x++) {
                        DPMIN[y][x] = min({A[y][x], DPMIN[y-1][x], DPMIN[y][x-1]});
                        DPMAX[y][x] = max({A[y][x], DPMAX[y-1][x], DPMAX[y][x-1]});
                        if (DPMIN[y][x] + (y-starty+1)*(x-startx+1) - 1 == DPMAX[y][x]) {
                            ++res;
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<t<<'\n'<<res<<endl;
=======
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
>>>>>>> 2d8c2d02d42975dbb79638bed5e25557b3f26cd5
    }
}