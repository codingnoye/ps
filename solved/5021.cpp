#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, M; cin>>N>>M;
    string king; cin>>king;

    map<string, pair<int, vector<string>>> G; // key, <degree, <childs>>
    map<string, double> power;

    while (N--) {
        string c, p1, p2; cin>>c>>p1>>p2;
        if (G.find(p1) == G.end()) G[p1] = {0, {c}};
        else G[p1].second.push_back(c);
        if (G.find(p2) == G.end()) G[p2] = {0, {c}};
        else G[p2].second.push_back(c);
        if (G.find(c) == G.end()) G[c] = {2, {}};
        else G[c].first = 2;
    }

    queue<string> Q;
    Q.push(king);
    for (auto& [k, v]: G) {
        auto& [deg, childs] = v;
        if (deg == 0) Q.push(k);
    }
    power[king] = 1;
    while (!Q.empty()) {
        string now = Q.front(); Q.pop();
        for (string ch: G[now].second) {
            power[ch] += power[now] / 2;
            if (--(G[ch].first) == 0) Q.push(ch);
        }
    }

    double mx = 0;
    string mxc = "";
    while (M--) {
        string cand; cin>>cand;
        double val = power[cand];
        if (mx < val) {
            mx = val;
            mxc = cand;
        }
    }
    cout<<mxc<<endl;
}