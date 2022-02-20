#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    int gr = 0;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        gr ^= x;
    }
    if (gr) cout<<"koosaga"<<endl;
    else cout<<"cubelover"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}