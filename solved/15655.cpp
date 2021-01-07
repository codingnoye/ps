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

int N, M;
int arr[10];
int trace[10];
void dfs(int now, int lasti) {
    if (now == M) {
        for (int i=0; i<M; i++) cout<<trace[i]<<' ';
        cout<<endl;
        return;
    }
    for (int i=lasti+1; i<N; i++) {
        trace[now] = arr[i];
        dfs(now+1, i);
    }
}
void solve() {
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
    dfs(0, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}