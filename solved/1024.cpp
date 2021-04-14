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

void solve() {
    ull N, L; cin>>N>>L;
    for (ull i=L; i<=100; i++) {
        int s=0, e=1000000000;
        ull m;
        while (s < e) {
            m = (s+e) / 2;
            if (2*N == 2*m*i + i*(i - 1)) {
                for (int j=m; j<m+i; j++) cout<<j<<' ';
                cout<<endl;
                return;
            } else if (2*N >= 2*m*i + i*(i - 1)) s = m + 1;
            else e = m;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}