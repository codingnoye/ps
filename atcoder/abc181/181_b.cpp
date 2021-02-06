#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

ull sm(ull x) {
    return (x * (x+1)) / 2;
}

void solve() {
    int N; cin>>N;
    ull res = 0;
    while (N--) {
        ull a, b; cin>>a>>b;
        res += sm(b) - sm(a-1);
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}