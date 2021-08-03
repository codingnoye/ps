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

// sum of [s, e)
int cumsum(vector<int>& cum, int s, int e) {
    return cum[e] - cum[s];
}
void solve() {
    int N, L; cin>>N>>L;
    vector<int> cum(N+1);
    cum[0] = 0;
    for(int i=0; i<N; i++) {
        int x; cin>>x;
        cum[i+1] = cum[i] + x;
    }
    double minval = 99999999;
    for (int i=0; i<N; i++) {
        for (int j=i+L; j<=N; j++) {
            //cout<<cumsum(cum, i, i+1)<<' '<<cumsum(cum, j-1, j)<<' '<<cumsum(cum, i, j)<<endl;
            minval = min(minval, (((double)cumsum(cum, i, j))/(j-i)));
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<minval<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int C; cin>>C;
    while (C--)
        solve();
    return 0;
}