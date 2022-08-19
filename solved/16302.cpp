#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

class UF {
public:
    vector<int> parent;
    UF (int n) {
        parent = vector<int>(n);
        for (int i=0; i<n; i++) parent[i] = i;
    }
    int f(int x) {
        int px = parent[x];
        if (px == x) return x;
        return parent[x] = f(px);
    }
    bool u(int x, int y) {
        int px = f(x);
        int py = f(y);
        if (px == py) return false;
        parent[px] = py;
        return true;
    }  
};

ll get_diff(string s1, string s2) {
    ll cost = 0;
    for (int i=0; i<s1.size(); i++) {
        if (s1[i] != s2[i]) cost++;
    }
    return cost;
}

int main() {
    fastio;
    
    vector<string> DNAs;
    int N, K; cin>>N>>K;

    vector<pair<ll, pair<int, int>>> edges;

    for (int i=0; i<N; i++) {
        string s; cin>>s;
        DNAs.push_back(s);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            edges.push_back({get_diff(DNAs[i], DNAs[j]), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    UF uf(N);
    int res = 0;
    vector<pair<int, int>> log;
    for (auto [cost, nodes]: edges) {
        if (uf.u(nodes.first, nodes.second)) {
            res += cost;
            log.push_back(nodes);
        }
    }
    cout<<res<<endl;
    for (auto& [u, v]: log) {
        cout<<u<<' '<<v<<endl;
    }
}