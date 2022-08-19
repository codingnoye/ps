#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    string S; cin>>S;

    string res = "";
    for (auto c: S) {
        if (c == 'e') res += "ee";
        else res += c;
    }
    cout<<res<<endl;
}