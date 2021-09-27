#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N, M; cin>>N>>M;
    int y1, y2; cin>>y1>>y2;
    vector<int> P(N), Q(M);
    for (int i=0; i<N; i++) cin>>P[i];
    for (int i=0; i<M; i++) cin>>Q[i];
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    int pi=0, qi=0;
    int mn = 987654321;
    int cnt = 0;
    while (pi<N-1 && qi<M-1) {
        int d = abs(P[pi] - Q[qi]);
        if (mn > d) {
            mn = d;
            cnt = 1;
        } else if (mn == d) {
            cnt++;
        }
        if (P[pi] < Q[qi]) pi++;
        else qi++;
    }
    while (qi<M-1) {
        int d = abs(P[pi] - Q[qi]);
        if (mn > d) {
            mn = d;
            cnt = 1;
        } else if (mn == d) {
            cnt++;
        }
        qi++;
    }
    while (pi<N-1) {
        int d = abs(P[pi] - Q[qi]);
        if (mn > d) {
            mn = d;
            cnt = 1;
        } else if (mn == d) {
            cnt++;
        }
        pi++;
    }
    int d = abs(P[pi] - Q[qi]);
        if (mn > d) {
            mn = d;
            cnt = 1;
        } else if (mn == d) {
            cnt++;
        }
    cout<<(mn + abs(y1 - y2))<<' '<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}