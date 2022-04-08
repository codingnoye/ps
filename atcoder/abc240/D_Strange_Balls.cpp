#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int N; cin>>N;
    vector<pii> cyl(N);
    int s = 0;
    int c = 0;
    int last = -1;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        if (last == x) {
            cyl[s-1].second++;
            c++;
            if (cyl[s-1].second >= last) {
                c -= cyl[s-1].second;
                s--;
                last = cyl[s-1].first;
            }
        } else {
            cyl[s++] = {x, 1};
            last = x;
            c++;
        }
        cout<<c<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}