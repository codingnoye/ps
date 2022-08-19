#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int M; cin>>M;
    vector<pair<int, int>> P;
    while (true) {
        int a, b; cin>>a>>b;
        if (!a && !b) break;
        if (a > b) swap(a, b);
        if (b <= 0) continue;
        if (a < 0) a = 0;
        P.push_back({a, b});
    }
    sort(P.begin(), P.end());

    int i = 0;
    int now = 0;
    int cnt = 0;
    while (now < M) {
        int next = now;
        int j = i;
        while (j < P.size()) {
            auto [s, e] = P[j];
            if (s <= now && now <= e) {
                next = max(next, e);
            } else if (now < s) break;
            j++;
        }
        if (now == next) break;
        i = j;
        cnt++;
        now = next;
    }
    if (now < M) cnt = 0;
    cout<<cnt<<endl;
}