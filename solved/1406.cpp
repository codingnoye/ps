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
    string s; cin>>s;
    stack<char> left, right;
    for (char c:s) left.push(c);
    int N; cin>>N;
    while (N--) {
        char x; cin>>x;
        if (x=='L') {
            if (left.empty()) continue;
            right.push(left.top());
            left.pop();
        } else if (x=='D') {
            if (right.empty()) continue;
            left.push(right.top());
            right.pop();
        } else if (x=='B') {
            if (left.empty()) continue;
            left.pop();
        } else {
            char y; cin>>y;
            left.push(y);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout<<right.top();
        right.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}