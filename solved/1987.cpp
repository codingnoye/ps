#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[21][21] = {0};
bool visited[27] = {false};
int ans = 0;
int R, C; 

void dfs(int x, int y, int len) {
    const int now = arr[y][x];
    if (x<0 || x>=C || y<0 || y>=R) return;
    if (visited[now]) return;
    visited[now] = true;
    ans = max(ans, len);
    dfs(x-1, y, len+1);
    dfs(x+1, y, len+1);
    dfs(x, y+1, len+1);
    dfs(x, y-1, len+1);
    visited[now] = false;
}
int main() {
    cin>>R>>C;
    string tmp;
    for (int r=0; r<R; r++) {
        cin>>tmp;
        for (int c=0; c<C; c++) {
            arr[r][c] = tmp.at(c) - 'A';
        }
    }
    dfs(0, 0, 1);
    cout<<ans;
}