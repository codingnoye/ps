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
        int N; cin>>N;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (i==j || i==(j+1)%N) cout<<1<<' ';
                else cout<<0<<' ';
            }
            cout<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}