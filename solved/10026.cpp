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

int N;
int arr[100][100];
int visited[100][100];

void dfs(int x, int y, int mask, int color) {
    if (x<0 || x>=N || y<0 || y>=N) return;
    if ((visited[x][y] & mask) != 0) return;
    if (mask == 2 && color != arr[x][y]) return;
    if (mask == 1 && color/2 != arr[x][y]/2) return;
    visited[x][y] = mask | visited[x][y];
    dfs(x-1, y, mask, color);
    dfs(x+1, y, mask, color);
    dfs(x, y-1, mask, color);
    dfs(x, y+1, mask, color);
}

void solve() {
    cin>>N;
    for (int i=0; i<N; i++) {
        string tmp; cin>>tmp;
        for (int j=0; j<N; j++) {
            if (tmp.at(j)=='R')
                arr[i][j] = 0;
            else if (tmp.at(j)=='G')
                arr[i][j] = 1;
            else if (tmp.at(j)=='B')
                arr[i][j] = 2;
        }
    }
    int res1 = 0, res2 = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if ((visited[i][j]&1) == 0) {
                res1++;
                dfs(i, j, 1, arr[i][j]);
            }
            if ((visited[i][j]&2) == 0) {
                res2++;
                dfs(i, j, 2, arr[i][j]);
            }
        }
    }
    cout<<res2<<" "<<res1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}