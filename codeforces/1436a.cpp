#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
#define endl '\n'

void solve() {
    int T; cin>>T;
    while (T--) {
        int N, M, x, n=0; cin>>N>>M;
        while (N--) {
            cin>>x;
            n += x;
        }
        cout<<(n==M?"YES":"NO")<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}