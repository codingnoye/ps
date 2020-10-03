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
ull accum(ull x) {
    if (x<=1) return x;
    ull res = 0;
    ull size = 1;
    ull level = 0;
    while (size*2<=x) size<<=1, level++;
    res = (size/2)*level;
    res += x-size+1;
    res += accum(x-size);
    return res;
}

void solve() {
    ull a, b; cin>>a>>b;
    cout<<(accum(b)-accum(a-1))<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}