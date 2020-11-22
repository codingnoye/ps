#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void solve() {
    int N, X; cin>>N>>X;
    string tmp; cin>>tmp;
    int s = X;
    for (char c: tmp) {
        if (c=='o') s++;
        else if (s>0) s--;
    }
    cout<<s<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}