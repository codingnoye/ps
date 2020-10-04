#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[17][17] = {0};
int cnt[17][17][3] = {0}; // 0: -, 1:\, 2:|

void solve() {
    int N; cin>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>arr[i][j];
        }
    }
    cnt[1][2][0] = 1;
    for (int i=1; i<17; i++) {
        for (int j=1; j<17; j++) {
            if (arr[i][j]==0)
                cnt[i][j][0] += cnt[i][j-1][0] + cnt[i][j-1][1];
            if (arr[i][j]==0 && arr[i-1][j]==0 && arr[i][j-1]==0)
                cnt[i][j][1] += cnt[i-1][j-1][0] + cnt[i-1][j-1][1] + cnt[i-1][j-1][2];
            if (arr[i][j]==0)   
                cnt[i][j][2] += cnt[i-1][j][1] + cnt[i-1][j][2];
        }
    }
    cout<<(cnt[N][N][0]+cnt[N][N][1]+cnt[N][N][2])<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}