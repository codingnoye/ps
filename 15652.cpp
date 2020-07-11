#include <iostream>
using namespace std;
int history[9] = {0};
int n, m;
void solve(int now, int last) {
    if (now>m) {
        for (int j=1; j<=m; j++) cout<<history[j]<<" ";
        cout<<'\n';
        return;
    }
    for (int i=last; i<=n; i++) {
        history[now] = i;
        solve(now+1, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    solve(1, 1);
}