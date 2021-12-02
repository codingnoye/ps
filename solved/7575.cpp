#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

// pi 반환
vector<int> make_pi(vector<int> pattern) {
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
bool kmp(vector<int> text, vector<int> pattern, vector<int> pi) {
    int n = text.size();
    int m = pattern.size();
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
    int N, M; cin>>N>>M;
    vector<vector<int>> targets(N);
    for (int n=0; n<N; n++) {
        int K; cin>>K;
        for (int i=0; i<K; i++) {
            int x; cin>>x;
            targets[n].push_back(x);
        }
    }
    int S = targets[0].size();
    vector<int> pattern;
    vector<int> patternR;
    bool found;
    for (int i=0; i<=S-M; i++) {
        found = true;
        for (int j=0; j<M; j++) {
            pattern.push_back(targets[0][i+j]);
            patternR.push_back(targets[0][i+j]);
        }
        reverse(patternR.begin(), patternR.end());
        vector<int> pi = make_pi(pattern);
        vector<int> piR = make_pi(patternR);
        for (int j=1; j<N; j++) {
            if (!(kmp(targets[j], pattern, pi) || kmp(targets[j], patternR, piR))) {
                found = false;
                break;
            }
        }
        if (found) break;
        pattern.clear();
        patternR.clear();
    }
    if (found) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}