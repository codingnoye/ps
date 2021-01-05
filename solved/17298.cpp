#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int res[10000001];
void solve() {
    int N; cin>>N;
    stack<ii> st;
    for (int i=0; i<N; i++) {
        res[i] = -1;
        int k; cin>>k;
        while (!st.empty()) {
            ii t = st.top();
            if (t.first<k) {
                st.pop();
                res[t.second] = k;
            } else break;
        }
        st.push({k, i});
    }
    for (int i=0; i<N; i++) {
        cout<<res[i]<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}