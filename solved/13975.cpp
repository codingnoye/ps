#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        while (N--) {
            ll x; cin>>x;
            pq.push({x, 0});
        }

        while (pq.size() >= 2) {
            pair<ll, ll> a = pq.top(); pq.pop();
            pair<ll, ll> b = pq.top(); pq.pop();
            pq.push({a.first + b.first, a.second + b.second + a.first + b.first});
        }
        cout<<pq.top().second<<endl;
    }
}