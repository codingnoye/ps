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
    int N, S, D; cin>>N>>S>>D;
    bool attacked = false;
    for (int i=0; i<N; i++) {
        int x, y; cin>>x>>y;
        if (!(x>=S || y<=D)) attacked = true;
    }
    cout<<(attacked?"Yes":"No")<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}