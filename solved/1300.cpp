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

ull N;

ull get_le_then(ull x) {
    ull s = 0;
    for (int i=1; i<=min(x, N); i++) {
        s += min(x, i*N)/i;
    }
    return s;
}

void solve() {
    cin>>N;
    ull K; cin>>K;
    ull s=1, m, e=N*N;
    while (s < e) {
        m = (s+e) / 2;
        if (get_le_then(m) >= K)
            e = m;
        else
            s = m+1;
    }
    cout<<e<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}