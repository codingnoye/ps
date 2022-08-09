#include <bits/stdc++.h>
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        ll ans = 0;

        int N; cin>>N;
        vector<pair<ll, ll>> points(N); // y, x

        map<ll, vector<ll>> ytox, xtoy;
        ff(i, 0, N) {
            ll y, x; cin>>y>>x;
            points[i] = {y, x};
            ytox[y].push_back(x);
            xtoy[x].push_back(y);
        }

        ll rem_y, rem_x;
        bool rem_exist = false;

        for (auto& [y, xs] : ytox) {
            if (xs.size()%2 == 1) {
                rem_y = y;
                rem_exist = true;
                break;
            }
        }
        for (auto& [x, ys] : xtoy) {
            if (ys.size()%2 == 1) {
                rem_x = x;
                rem_exist = true;
                break;
            }
        }

        ll res = 0;
        for (auto& [y, xs] : ytox) {
            sort(xs.begin(), xs.end());
            for (int i=0; i<xs.size();) {
                if (rem_exist && y == rem_y) {
                    if (xs[i] == rem_x) {
                        i+=1;
                        continue;
                    } else if (xs[i+1] == rem_x) {
                        res += xs[i+2] - xs[i];
                        i+=3;
                        continue;
                    }
                }
                res += xs[i+1] - xs[i];
                i += 2;
            }
        }
        for (auto& [x, ys] : xtoy) {
            sort(ys.begin(), ys.end());
            for (int i=0; i<ys.size();) {
                if (rem_exist && x == rem_x) {
                    if (ys[i] == rem_y) {
                        i+=1;
                        continue;
                    } else if (ys[i+1] == rem_y) {
                        res += ys[i+2] - ys[i];
                        i+=3;
                        continue;
                    }
                }
                res += ys[i+1] - ys[i];
                i += 2;
            }
        }
        cout<<"Case #"<<C<<endl<<res<<endl;
    }
}