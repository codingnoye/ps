#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef pair<ib, int> ibi;

void solve() {
    int N; cin>>N;
    vector<ibi> v;
    for (int i=0; i<N; i++) {
        int s, e; cin>>s>>e;
        if (e<s) swap(s, e);
        v.push_back(ibi{ib{s, true}, i});
        v.push_back(ibi{ib{e, false}, i});
    }
    int D; cin>>D;
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> contain;
    int mx = 0;
    int cnt = 0;
    for (auto it=v.begin(); it<v.end(); it++) {
        int n = it->first.first;
        bool isHome = it->first.second;
        int id = it->second;
        if (isHome) {
            contain[id] = n;
        } else {
            pq.push(contain[id]);
            contain.erase(id);
            cnt++;

            while (!pq.empty() && n - pq.top() > D) {
                pq.pop();
                cnt--;
            }
            mx = max(mx, cnt);
        }
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}