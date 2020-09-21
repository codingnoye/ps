#include <iostream>
using namespace std;

int st[8] = {0};
int N, M;

void solve(int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++) cout<<st[i]<<' ';
        cout<<'\n';
        return;
    }
    for (int i=1; i<=N; i++) {
        st[depth] = i;
        solve(depth+1);
    }
}

int main() {
    cin>>N>>M;
    solve(0);
}