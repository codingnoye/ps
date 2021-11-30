#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

// pi 반환
vector<int> make_pi(string pattern) {
    int m = pattern.size();
    int j = 0;
    vector<int> pi(m, 0);

    for (int i=1; i<m; i++) {
        while (j>0 && pattern[i] != pattern[j])
            j = pi[j-1];
        if (pattern[i] == pattern[j])
            pi[i] = ++j;    
    }
    return pi;
}
// 매칭된 문자열들의 시작점 리스트
vector<int> kmp(string text, string pattern) {
    vector<int> ans;
    vector<int> pi = make_pi(pattern);
    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for (int i=0; i<n; i++) {
        while (j>0 && text[i] != pattern[j])
            j = pi[j-1];
        if (text[i] == pattern[j]) {
            if (j == m-1) {
                ans.push_back(i-j);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}

void solve() {
    while (true) {
        string s; cin>>s;
        if (s == ".") break;
        auto pi = make_pi(s);
        int x = pi[s.size()-1];
        if (s.size() % (s.size() - x) == 0) {
            int res = s.size() / (s.size() - x);
            cout<<res<<endl;
        } else {
            cout<<1<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}