#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

void solve() {
    string inp; cin>>inp;
    stack<char> st;
    for (char c: inp) {
        if ('A'<=c && c<='Z') cout<<c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (st.top() != '(') {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        } else {
            if (!st.empty()) {
                if (c=='+'||c=='-') while (!st.empty() && st.top()!='(') {
                    cout<<st.top();
                    st.pop();
                }
                else if (c=='*'||c=='/') while (!st.empty() && (st.top()=='*'||st.top()=='/')) {
                    cout<<st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}