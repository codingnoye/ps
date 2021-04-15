#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

class dpq {
    priority_queue<ll, vector<ll>, less<ll>> gpq;
    priority_queue<ll, vector<ll>, greater<ll>> lpq;
    map<ll, ll> cnt;
public:
    bool E = false;
    void insert(ll a) {
        if (cnt.find(a) != cnt.end()) cnt[a]++;
        else cnt[a] = 1;
        gpq.push(a);
        lpq.push(a);
        E = false;
    }
    ll del(bool g, bool pop) {
        if (g) {
            if (gpq.size() == 0) {
                E = true;
                return 0;
            }
            while (cnt[gpq.top()]==0) {
                gpq.pop();
                if (gpq.size() == 0) {
                    E = true;
                    return 0;
                }
            }
            ll r = gpq.top();
            if (pop) {
                cnt[gpq.top()]--;
                gpq.pop();
            }
            return r;
        }
        else {
            if (lpq.size() == 0) {
                E = true;
                return 0;
            }
            while (cnt[lpq.top()]==0) {
                lpq.pop();
                if (lpq.size() == 0) {
                    E = true;
                    return 0;
                }
            }
            ll r = lpq.top();
            if (pop) {
                cnt[lpq.top()]--;
                lpq.pop();
            }
            return r;
        }
    }
};

void solve() {
    int T; cin>>T;
    while (T--) {
        dpq Q;
        int N; cin>>N;
        while (N--) {
            char C; ll X; cin>>C>>X;
            if (C=='I') Q.insert(X);
            else Q.del(X==1, true);
        }
        ll a = Q.del(true, false);
        ll b = Q.del(false, false);
        if (Q.E) cout<<"EMPTY"<<endl;
        else cout<<a<<' '<<b<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}