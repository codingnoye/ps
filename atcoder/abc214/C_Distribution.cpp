#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    vector<int> S(N);
    vector<int> T(N);
    vector<int> got(N, -1);
    int gotcnt = 0;
    for(int i = 0; i < N; i++) cin>>S[i];
    for(int i = 0; i < N; i++) cin>>T[i];
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < N; i++) {
        pq.push({T[i], i});
    }
    while (!pq.empty()) {
        pair<int, int> t = pq.top();
        pq.pop();
        if (got[t.second] == -1) {
            got[t.second] = t.first;
            gotcnt++;
            if (gotcnt == N) break;
        }
        pq.push({t.first+S[t.second], (t.second+1)%N});
    }
    for (int i=0; i<N; i++) {
        cout<<got[i]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}