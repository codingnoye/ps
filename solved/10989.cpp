#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int cnt[10001];
void solve() {
    int N; cin>>N;
    while (N--) {
        int x; cin>>x;
        cnt[x]++;
    }
    for (int i=0; i<10001; i++) {
        while (cnt[i]--) cout<<i<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}