#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int gcd(int p, int q) {
    return q == 0 ? p : gcd(q, p % q);
}

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
    int N; cin>>N;
    char sr[N+1];
    for (int i=0; i<N; i++) cin>>sr[i];
    string s(sr, sr+N);
    auto pi = make_pi(s);
    int x = pi[s.size()-1];
    int iter;
    if (s.size() % (s.size() - x) == 0) {
        iter = s.size() / (s.size() - x);
    } else {
        iter = 1;
    }
    int son = iter;
    int mom = N;
    int g = gcd(son, mom);
    if (g != 1) {
        son /= g;
        mom /= g;
    }
    cout<<son<<'/'<<mom<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}