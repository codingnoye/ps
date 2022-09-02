#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, T; cin>>N>>T;
    
    deque<char> dq;
    for (int i=0; i<N; i++) dq.push_back('a'+i);

    int cnt = 0;
    vector<char> res;
    while (T) {
        int now = min(T, (int)dq.size());
        res.push_back(dq[now-1]);
        dq.push_front(dq[now-1]);
        dq.pop_back();
        T -= now;
        cnt++;
    }
    cout<<cnt<<endl;
    for (char c: res) cout<<c<<' ';
    cout<<endl;
}