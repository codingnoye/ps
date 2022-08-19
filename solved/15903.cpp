#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int N, M; cin>>N>>M;
    for (int i=0; i<N; i++) {
        ll x; cin>>x;
        pq.push(x);
    }

    for (int i=0; i<M; i++) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll c = a+b;
        pq.push(c);
        pq.push(c);
    }

    ll res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    cout<<res<<endl;
}