#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void solve() {
    int N; cin>>N;
    vector<int> s;
    int res = 0;
    int x; cin>>x;
    s.push_back(x);
    for (int i=1; i<N; i++) {
        int x; cin>>x;
        for (auto it=s.rbegin(); it!=s.rend(); it++) {
            res++;
            if (*it < x) s.pop_back();
            if (*it > x) break;
        }
        s.push_back(x);
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}