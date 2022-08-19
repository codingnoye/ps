#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

typedef map<char, ll> molecules;

molecules parse_molecules(string s) {
    molecules m;
    char mol = ' ';
    ll mul = -1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if ('0'<=c && c<='9') {
            if (mul == -1) mul = (c-'0');
            else {
                mul *= 10;
                mul += (c-'0');
            }
        } else if ('A' <= c && c <= 'Z') {
            if (mol != ' ') {
                if (mul == -1) mul = 1;
                if (m.find(mol) == m.end()) m[mol] = 0;
                m[mol] += mul;
            }
            mol = c;
            mul = -1;
        }
    }
    if (mol != ' ') {
        if (mul == -1) mul = 1;
        if (m.find(mol) == m.end()) m[mol] = 0;
        m[mol] += mul;
    }
    return m;
}

int main() {
    fastio;
    
    string s1, s2; int n;
    cin>>s1>>n>>s2;

    molecules m1 = parse_molecules(s1);
    molecules m2 = parse_molecules(s2);

    for (auto& [k, v]: m1) {
        // cout<<k<<" "<<v<<endl;
        v *= n;
    }

    ll res = 10987654321LL;
    for (auto& [k, v]: m2) {
        // cout<<k<<" "<<v<<endl;
        if (m1.find(k) == m1.end()) {
            res = 0;
            break;
        }
        res = min(res, m1[k] / v);
    }
    if (res == 10987654321LL) res = 0;
    cout<<res<<endl;
}