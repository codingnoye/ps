#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

void solve() {
    int a, b, c; cin>>a>>b>>c;
    if (a==b) cout<<c<<endl;
    else if (b==c) cout<<a<<endl;
    else if (c==a) cout<<b<<endl;
    else cout<<0<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}