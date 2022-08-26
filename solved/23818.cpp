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
        if (px < py) swap(px, py);
        parent[px] = py;
        return true;
    }  
};


int main() {
    fastio;
    
    int N, M, K; cin>>N>>M>>K;
    UF uf(2*N);
    // [0, N-1]: node, [N, 2N-1]: anti

    for (int m=0; m<M; m++) {
        int t, a, b; cin>>t>>a>>b; a--; b--;

        if (t == 0) {
            uf.u(a, b);
            uf.u(a+N, b+N);
        } else {
            uf.u(a+N, b);
            uf.u(a, b+N);
        }
    }

    for (int k=0; k<K; k++) {
        int a, b; cin>>a>>b; a--; b--;

        bool frnd = uf.f(a) == uf.f(b);
        bool enemy = uf.f(a+N) == uf.f(b);
        if (frnd && enemy) cout<<"Error"<<endl;
        else if (frnd) cout<<"Friend"<<endl;
        else if (enemy) cout<<"Enemy"<<endl;
        else cout<<"Unknown"<<endl;
    }
}