#include <bits/stdc++.h>
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        ll ans = 0;

        int N; cin>>N;
        vector<pair<ll, ll>> points(N); // y, x

        map<ll, set<ll>> ytox, xtoy;
        ff(i, 0, N) {
            ll y, x; cin>>y>>x;
            points[i] = {y, x};
            ytox[y].insert(x);
            xtoy[x].insert(y);
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
        if (rem_exist) {
            ytox[rem_y].erase(rem_x);
            xtoy[rem_x].erase(rem_y);
        }

        ll res = 0;
        for (auto& [y, xs] : ytox) {
            for (auto it=xs.begin(); it!=xs.end(); advance(it, 2)) {
                auto it2 = next(it);
                res += *it2 - *it;
            }
        }
        for (auto& [x, ys] : xtoy) {
            for (auto it=ys.begin(); it!=ys.end(); advance(it, 2)) {
                auto it2 = next(it);
                res += *it2 - *it;
            }
        }

        cout<<"Case #"<<C<<endl<<res<<endl;
    }
}