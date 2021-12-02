#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

// depth = d일 때, 2^(d-1) 나타낼 수 있음
const int DEPTH = 18; // 131072
const int LEN = 1<<(DEPTH-1);
int tree[DEPTH][LEN];

void build (vector<int> seed) {
    for (int i=0; i<seed.size(); i++) {
        tree[DEPTH-1][i] = seed[i];
    }
    int s = 2;
    for (int d=DEPTH-2; d>=0; d--) {
        int hs = s/2;
        for (int i=0; i<LEN; i+=s) {
            int pi = 0;
            int li = 0;
            int ri = 0;
            while (li<hs && ri<hs) {
                if (tree[d+1][i+li] < tree[d+1][i+hs+ri])
                    tree[d][i+pi++] = tree[d+1][i+li++];
                else
                    tree[d][i+pi++] = tree[d+1][i+hs+ri++];
            }
            while (li<hs) tree[d][i+pi++] = tree[d+1][i+li++];
            while (ri<hs) tree[d][i+pi++] = tree[d+1][i+hs+ri++];
        }
        s*=2;
    }
}

int query(int d, int idx, int l, int r, int x) {
    int size = 1<<(DEPTH-d-1);
    int s = idx;
    int e = idx+size;
    if (l<=s && e<=r) {
        return size - (upper_bound(tree[d]+s, tree[d]+e, x) - (tree[d]+s));
    } else if (r<=s || e<=l) {
        return 0;
    } else {
        return query(d+1, idx, l, r, x) + query(d+1, idx+size/2, l, r, x);
    }
}

void solve() {
    int N; cin>>N;
    vector<int> seed(N);
    for (int i=0; i<N; i++) cin>>seed[i];
    build(seed);
    int M; cin>>M;
    while (M--) {
        int i, j, k; cin>>i>>j>>k;
        cout<<query(0, 0, i-1, j, k)<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}