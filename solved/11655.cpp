#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

void solve() {
    string s, res;
    getline(cin, s);
    res = "";
    
    for (char c: s) {
        if ('A'<=c && c<='Z') {
            res += string(1, (c-'A'+13) % ('Z'-'A'+1) + 'A');
        } else if ('a'<=c && c<='z') {
            res += string(1, (c-'a'+13) % ('z'-'a'+1) + 'a');
        } else {
            res += string(1, c);
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}