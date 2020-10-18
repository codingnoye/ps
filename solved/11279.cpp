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
    priority_queue<int> pq;
    while (N--) {
        int x; cin>>x;
        if (x==0) {
            if (pq.empty()) {
                cout<<0<<endl;
                continue;
            }
            cout<<pq.top()<<endl;
            pq.pop();
        } else {
            pq.push(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}