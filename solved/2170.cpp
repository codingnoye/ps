#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int N; cin>>N;
    
    vector<pii> V;
    while (N--) {
        int a, b; cin>>a>>b;
        V.push_back({a, b});
    }
    sort(V.begin(), V.end());

    pii nowrange = {-1000000001, -1000000001};
    ll cnt = 0;
    for (pii now: V) {
        if (now.first > nowrange.second) {
            cnt += nowrange.second - nowrange.first;
            nowrange.first = now.first;
            nowrange.second = now.second;
        } else {
            nowrange.second = max(now.second, nowrange.second);
        }
    }
    cnt += nowrange.second - nowrange.first;
    cout<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}