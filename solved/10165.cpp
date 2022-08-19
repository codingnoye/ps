#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

struct node {
    ll x;
    ll s;
    ll e;
    ll idx;
};

struct node2 {
    ll s;
    ll e;
    ll idx;
};

bool cmp (const node a, const node b) {
    return a.x == b.x ? a.e > b.e : a.x < b.x;
}
bool operator< (const node a, const node b) {
    return a.x == b.x ? a.e > b.e : a.x < b.x;
}
bool operator< (const node2 a, const node2 b) {
    return a.s == b.s ? a.e > b.e : a.s < b.s;
}

int main() {
    fastio;
    
    ll N, M; cin>>N>>M;
    vector<node> P; // <x, idx>
    for (ll i=1; i<=M; i++) {
        ll a, b; cin>>a>>b;
        if (a > b) {
            P.push_back({a, a, b+N, i});
            P.push_back({b+N, a, b+N, i});
        } else {
            P.push_back({a, a, b, i});
            P.push_back({b, a, b, i});
            P.push_back({a+N, a+N, b+N, i});
            P.push_back({b+N, a+N, b+N, i});
        }
    }
    sort(P.begin(), P.end(), cmp);

    ll now = 0;
    vector<int> removed(M+1);
    set<pair<ll, ll>> opened;
    for (auto& [x, s, e, idx]: P) {
        if (removed[idx] == 1) {
            continue;
        }
        if (opened.find({s, e}) != opened.end()) {
            opened.erase({s, e});
            continue;
        }
        bool openable = true;
        for (auto& [os, oe]: opened) {
            if (e <= oe) {
                removed[idx] = 1;
                openable = false;
                break;
            }
        }
        if (openable) {
            opened.insert({s, e});
        }
    }
    for (ll i=1; i<=M; i++) {
        if (removed[i] == 0) {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}