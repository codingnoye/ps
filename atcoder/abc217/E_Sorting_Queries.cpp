#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int Q; cin>>Q;
    priority_queue<int, vector<int>, greater<int>> sorted;
    queue<int> left;
    while (Q--) {
        int c; cin>>c;
        if (c==1) {
            int x; cin>>x;
            left.push(x);
        } else if (c==2) {
            if (sorted.empty()) {
                cout<<left.front()<<endl;
                left.pop();
            } else {
                cout<<sorted.top()<<endl;
                sorted.pop();
            }
        } else {
            while (!left.empty()) {
                sorted.push(left.front());
                left.pop();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}