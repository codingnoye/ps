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
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int arr[1001][1001];

void solve() {
    int N, M; cin>>N>>M;
    string tmp;
    for (int i=1; i<=N; i++) {
        cin>>tmp;
        for (int j=1; j<=M; j++) {
            arr[i][j] = tmp.at(j-1) - '0';
        }
    }
    int mx = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (arr[i][j] != 0) arr[i][j] = min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1])) + 1;
            
            mx = max(arr[i][j], mx);
        }
    }
    cout<<(mx*mx)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}