#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

vector<int> makepi(string S) {
    int j = 0;
    vector<int> pi(S.size(), 0);
    for (int i=1; i<S.size(); i++) {
        while (j>0 && S[i] != S[j])
            j = pi[j-1];
        if (S[i] == S[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string A, string B) {
    auto pi = makepi(B);
    vector<int> res;
    int j = 0;
    for (int i=0; i<A.size(); i++) {
        while (j>0 && A[i] != B[j])
            j = pi[j-1];
        if (A[i] == B[j]) {
            if (j == B.size()-1) {
                res.push_back(i-B.size()+1);
                j = pi[j];
            } else
                j++;
        }
    }
    return res;
}

void solve() {
    string A, B;
    getline(cin, A);
    getline(cin, B);
    auto res = kmp(A, B);
    cout<<res.size()<<endl;
    for (int i: res) {
        cout<<(i+1)<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}