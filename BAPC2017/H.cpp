#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

struct P{
    ll x;
    ll y;
    P(ll x=0, ll y=0) : x(x), y(y){}    
};
bool operator< (P A, P B) {
    return pair{A.x, A.y} < pair{B.x, B.y};
}
bool operator<= (P A, P B) {
    return pair{A.x, A.y} <= pair{B.x, B.y};
}
bool operator== (P A, P B) {
    return pair{A.x, A.y} == pair{B.x, B.y};
}

// a, b, c 순서로 Counter clockwise라면 양수
// 절대값에 2를 나누면 면적
ll ccw(P a, P b, P c, bool sign_only=false) {
    ll l = (b.x - a.x) * (c.y - a.y);
    ll r = (b.y - a.y) * (c.x - a.x);
    return l < r ? -1 : l > r ? 1 : 0;
}

// 선분 교차
bool is_intersect(P A1, P A2, P B1, P B2) {
    ll ccw1 = ccw(A1, A2, B1, true)*ccw(A1, A2, B2, true);
    ll ccw2 = ccw(B1, B2, A1, true)*ccw(B1, B2, A2, true);
    if (ccw1 == 0 && ccw2 == 0) {
        if (A2 < A1) swap(A1, A2);
        if (B2 < B1) swap(B1, B2);
        return (A1 <=B2 && B1 <= A2 );
    }
    return ccw1 <= 0 && ccw2 <= 0;
}

vector<pair<P, P>> fences;

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
        if (px < py) swap(px, py);
        parent[px] = py;
        return true;
    }  
};

int main() {
    fastio;

    int N; cin>>N;

    UF uf = UF(N);

    for (int i=0; i<N; i++) {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        ll endsame = 0;
        for (int j=0; j<i; j++) {
            auto& fence = fences[j];
            if (is_intersect(fence.first, fence.second, P(x1, y1), P(x2, y2))) {
                uf.u(j, i);
            }
        }
        fences.push_back({P(x1, y1), P(x2, y2)});
    }

    vector<vector<pair<P, P>>> graphs(N);
    for (int i=0; i<N; i++) {
        graphs[uf.f(i)].push_back(fences[i]);
    }
    
    ll res = 0;
    ll deb = 0;
    for (auto& graph: graphs) {
        if (graph.size() == 0) continue;
        ll v=0, e=0;

        for (int i=0; i<graph.size(); i++) {
            ll c = 0;
            auto& [F, S] = graph[i];
            for (int j=0; j<i; j++) {
                auto& [OF, OS] = graph[j];
                if (is_intersect(OF, OS, F, S)) {
                    c++;
                }
            }
            v += 2 + c;
            e += 1 + c + c;
            // cout<<"("<<F.x<<", "<<F.y<<") ("<<S.x<<", "<<S.y<<") "<<c<<endl;
            // cout<<c<<" "<<(1-v+e)<<endl;
        }
        res += max(1-v+e, 0LL);
        
        // cout<<"graph "<<deb++<<" "<<max(1-v+e, 0LL)<<endl;
    }
    cout<<res<<endl;
}