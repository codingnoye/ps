#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll sab(ll a, ll b) {
    return (b-a+1)*(a+b)/2LL;
}

void solve() {
    ll N, K; cin >> N >> K;
    priority_queue<pair<ll, ll>> pq;
    for (ll i = 0; i < N; i++) {
        ll x; cin >> x;
        pq.push({x, 1});
    }
    pq.push({0, 1});
    ll res = 0;
    while (!pq.empty() && K>0) {
        pair<ll, ll> now = pq.top(); pq.pop();
        pair<ll, ll> next;
        if (now.first == 0) break;
        int cnt = now.second;
        while (!pq.empty()) {
            next = pq.top();
            pq.pop(); 
            if (next.first != now.first) break;
            cnt+=next.second;
        }
        // cout<<"now "<<now.first<<","<<now.second<<" next "<<next.first<<","<<next.second<<endl;
        // cout<<res<<endl;
        ll full_cnt = (now.first - next.first) * cnt;
        if (full_cnt <= K) {
            ll delta = now.first - next.first;
            res += sab(next.first+1, now.first)*cnt;
            K -= full_cnt;
            pq.push({next.first, cnt + next.second});
            // cout<<res<<endl;
        } else {
            ll first_step = K / cnt;
            ll delta = first_step;
            res += sab(now.first-first_step+1, now.first)*cnt;
            // cout<<res<<endl;
            K -= first_step*cnt;
            res += (now.first - first_step)*K;
            // cout<<res<<endl;
            break;
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}