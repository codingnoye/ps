#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

void solve() {
    int N; cin>>N;
    vector<int> orgarr;
    vector<pair<int, int>> newarr;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        orgarr.push_back(x);
        newarr.push_back(make_pair(x, i));
    }
    sort(newarr.begin(), newarr.end());
    vector<int> res(N);
    for (auto it=newarr.begin(); it!=newarr.end(); it++) {
        res[(*it).second] = it-newarr.begin();
    }
    for (auto it=res.begin(); it!=res.end(); it++) {
        cout<<(*it)<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}