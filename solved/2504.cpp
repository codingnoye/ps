#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;


struct entry {
    int mul;
    vector<int> values;
};
void solve() {
    string S; cin>>S;

    stack<char> stc;
    vector<entry> st;
    st.push_back({1, {}});

    for (char c: S) {
        if (c == '(') {
            st.push_back({2, {}});
        } else if (c == ')') {
            if (st.back().mul != 2) {
                cout<<0<<endl;
                return;
            }
            int res = 0;
            for (int v: st.back().values) {
                res += v;
            }
            if (res == 0) res = 1;
            res = st.back().mul * res;
            st.pop_back();
            st.back().values.push_back(res);
        } else if (c == '[') {
            st.push_back({3, {}});
        } else { // c == ']'
            if (st.back().mul != 3) {
                cout<<0<<endl;
                return;
            }
            int res = 0;
            for (int v: st.back().values) {
                res += v;
            }
            if (res == 0) res = 1;
            res = st.back().mul * res;
            st.pop_back();
            st.back().values.push_back(res);
        }
    }
    if (st.size() != 1) {
        cout<<0<<endl;
        return;
    }
    int res = 0;
    for (int v: st.back().values) {
        res += v;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}