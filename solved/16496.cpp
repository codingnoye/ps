#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

bool cmp(string a, string b) {
    return (a=="0" ? b : a+b) > (b=="0" ? a : b+a);
}

int main() {
    fastio;

    int N; cin>>N;

    vector<string> A(N);
    for (int i=0; i<N; i++) cin>>A[i];
    sort(all(A), cmp);

    int cntzero = 0;
    for (string s: A) if (s=="0") cntzero++;

    if (cntzero == N)
        cout<<"0";
    else
        for (string s: A) cout<<s;
    cout<<endl;
}