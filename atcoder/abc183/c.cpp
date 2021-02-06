#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ull, ull> puu;
typedef pair<ll, ll> pll;

int N, K;
int arr[9][9];
bool visited[9];
int cnt = 0;
int cost = 0;
int res = 0;

void dfs(int now) {
    if (cnt == N-1) {
        if (cost + arr[now][0] == K) {
            res++;
        }
    } else for (int i=1; i<N; i++) {
        if (!visited[i]) {
            cost += arr[now][i];
            visited[i] = true;
            cnt++;
            dfs(i);
            cnt--;
            visited[i] = false;
            cost -= arr[now][i];
        }
    }
}

void solve() {
    cin>>N>>K;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    dfs(0);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}