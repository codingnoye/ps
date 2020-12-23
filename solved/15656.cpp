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
int arr[8];
int trace[8];
void dfs(int n) {
    if (n==M) {
        for (int i=0; i<M; i++) {
            cout<<trace[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for (int i=0; i<N; i++) {
        trace[n] = arr[i];
        dfs(n+1);
    }
}
void solve() {
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+N);
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}