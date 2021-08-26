#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 987654321;

struct w_edge {
    int from;
    int to;
    int weight;
};
vector<w_edge> G;
ll W[501];
void solve() {
    int N, M; cin>>N>>M;
    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        G.push_back({a, b, c});
    }
    W[1] = 0;
    for (int i=2; i<=N; i++) {
        W[i] = INF;
    }
    for (int c=0; c<N; c++) {
        bool changed = false;
        for (w_edge E: G) {
            if (W[E.from] == INF) continue;
            ll newW =  W[E.from] + E.weight;
            if (newW < W[E.to]) {
                W[E.to] = newW;
                changed = true;
            }
        }
        if (!changed) {
            break;
        } else if (c == N-1) {
            cout<<"-1"<<endl;
            return;
        }
    }
    for (int i=2; i<=N; i++) {
        if (W[i] == INF)
            cout<<"-1"<<endl;
        else
            cout<<W[i]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}