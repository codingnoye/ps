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

int main() {
    fastio;
    
    while (true) {
        int N, M, K; cin>>N>>M>>K;
        if (!N && !M && !K) break;

        vector<pair<int, int>> blue_edges;
        vector<pair<int, int>> red_edges;

        for (int m=0; m<M; m++) {
            char c; int a, b; cin>>c>>a>>b;
            if (c == 'B') blue_edges.push_back({a, b});
            else red_edges.push_back({a, b});
        }

        UF uf1(N+1), uf2(N+1);
        int used_be = 0, used_re = 0;

        for (auto& [a, b]: blue_edges) {
            if (uf1.u(a, b)) used_be++;
        }
        for (auto& [a, b]: red_edges) {
            if (uf1.u(a, b)) used_re++;
        }
        if (used_be + used_re < N-1) {
            cout<<0<<endl;
            continue;
        }
        int max_blue = used_be;

        used_be = 0, used_re = 0;
        for (auto& [a, b]: red_edges) {
            if (uf2.u(a, b)) used_re++;
        }
        for (auto& [a, b]: blue_edges) {
            if (uf2.u(a, b)) used_be++;
        }
        if (used_be + used_re < N-1) {
            cout<<0<<endl;
            continue;
        }
        int min_blue = used_be;

        if (max_blue >= K && min_blue <= K) cout<<1<<endl;
        else cout<<0<<endl;
    }
}