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

int ntr[100];
void solve() {
    int N, dc, tc, dn; cin>>N>>dc>>tc>>dn;
    for (int i=0; i<N; i++) cin>>ntr[i];
    sort(ntr, ntr+N);
    int c=dc, n=dn;
    int mx = dn/dc;
    for (int i=0; i<N; i++) {
        int nown = n + ntr[N-1-i];
        int nowc = c + tc;
        if (nown/nowc < mx) break;
        mx = nown/nowc;
        n = nown;
        c = nowc;
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}