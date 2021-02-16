#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

const int DEF_NODE = 1000000001;
const int ROOT = 1;
int N;
ii tree[400002];
// [N, 2N) = terminal
// terminal = 0 based, tree[N+i]
void build(int n) {
    for (N=1; N<n; N*=2);
}
void update(int n) {
    while (n) {
        int left = n*2;
        int right = left+1;
        if (tree[left].second<=tree[right].second) tree[n] = tree[left];
        else tree[n] = tree[right];
        n/=2;
    }
}
void update(int i, int v) {
    int n = N+i;
    tree[n].second = v;
    update(n/2);
}

void solve() {
    int n; cin>>n;
    build(n);
    for (int i=N; i<2*N; i++) tree[i].first = i-N;
    for (int i=N; i<N+n; i++) cin>>tree[i].second;
    for (int i=N+n; i<2*N; i++) tree[i].second = DEF_NODE;
    for (int i=N/2; i<N; i++) update(i);
    int M; cin>>M;
    while (M--) {
        int x; cin>>x;
        if (x==1) {
            int i, v; cin>>i>>v;
            update(i-1, v);
        } else {
            //for (int i=1; i<2*N; i++) cout<<'('<<tree[i].first<<','<<tree[i].second<<") ";
            //cout<<endl;
            cout<<(tree[ROOT].first+1)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}