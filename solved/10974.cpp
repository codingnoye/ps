#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int record[9];
bool used[9];
int N;
void dfs(int now) {
    if (now==N) {
        for (int i=0; i<N; i++) {
            cout<<record[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for (int i=1; i<=N; i++) {
        if (!used[i]) {
            record[now] = i;
            used[i] = true;
            dfs(now+1);
            used[i] = false;
        }
    }
}

void solve() {
    cin>>N;
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}