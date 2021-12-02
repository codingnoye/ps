#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

// pi 반환
vector<int> make_pi(vector<bool> pattern) {
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
bool kmp(vector<bool> text, vector<bool> pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = make_pi(pattern);
    int j = 0;

    for (int i=0; i<n; i++) {
        while (j>0 && text[i] != pattern[j])
            j = pi[j-1];
        if (text[i] == pattern[j]) {
            if (j == m-1) {
                return true;
            } else {
                j++;
            }
        }
    }
    return false;
}

void solve() {
    int N; cin>>N;
    vector<bool> pattern(360000);
    vector<bool> text(720000);
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        pattern[x] = true;
    }
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        text[x] = true;
        text[360000+x] = true;
    }
    if (kmp(text, pattern)) {
        cout<<"possible"<<endl;
    } else {
        cout<<"impossible"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}