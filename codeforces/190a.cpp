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
    int A, B, C; cin>>A>>B>>C;
    if (C==1) {
        if (B>A) cout<<"Aoki"<<endl;
        else cout<<"Takahashi"<<endl;
    } else {
        if (B>=A) cout<<"Aoki"<<endl;
        else cout<<"Takahashi"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}