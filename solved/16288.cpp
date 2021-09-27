#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    vector<stack<int>> st;
    int n, k, m;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        bool check = false;
        cin >> m;
        for(int j = 0; j < st.size(); j++) {
            if(st[j].top() < m) {
                st[j].push(m);
                check = true;
                break;
            }
        }
        if(!check) {
            st.push_back(stack<int>());
            st.back().push(m);
        }
    }

    cout << (st.size() > k ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}