#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    string S; cin>>S;
    vector<char> st;
    
    for (char c: S) {
        st.push_back(c);
        while (st.size() >= 4) {
            if (st[st.size()-4] == 'P' && st[st.size()-3] == 'P' && st[st.size()-2] == 'A' && st[st.size()-1] == 'P') {
                st.pop_back(); st.pop_back(); st.pop_back(); st.pop_back();
                st.push_back('P');
                continue;
            }
            break;
        }
    }
    if (st.size() == 1 && st[0] == 'P') cout<<"PPAP"<<endl;
    else cout<<"NP"<<endl;
}