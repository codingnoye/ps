#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#ifndef DEBUG
#define endl '\n'
#endif
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int N;
int arr[128][128];
int res0 = 0;
int res1 = 0;

void dfs(int sy, int sx, int n) {
    bool same = true;
    int val = -1;
    for (int y=sy; y<sy+n; y++) {
        for (int x=sx; x<sx+n; x++) {
            if (arr[y][x]==val || val==-1) {
                val = arr[y][x];
            } else {
                same = false;
                break;
            }
        }
    }
    if (same) {
        if (val==0)
            res0++;
        else
            res1++;
    } else {
        int newn = n/2;
        dfs(sy, sx, newn);
        dfs(sy+newn, sx, newn);
        dfs(sy, sx+newn, newn);
        dfs(sy+newn, sx+newn, newn);
    }
}

void solve() {
    cin>>N;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    dfs(0, 0, N);
    cout<<res0<<endl<<res1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}