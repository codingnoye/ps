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
int arr[100001];
void solve() {
    int N, M; cin>>N>>M;
    for (int i=1; i<=N; i++) {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    while (M--) {
        int a, b; cin>>a>>b;
        cout<<(arr[b]-arr[a-1])<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}