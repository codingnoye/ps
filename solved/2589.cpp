#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int H, W;
int mx = 0;
int map[51][51];

bool visited[51][51];
void bfs(int sy, int sx) {
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            visited[y][x] = false;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 0});
    while (!q.empty()) {
        auto [y, x] = q.front().first;
        int d = q.front().second;
        q.pop();
        if (visited[y][x]) continue;
        visited[y][x] = true;
        mx = max(mx, d);
        if (x+1 < W && map[y][x+1] == 1 && !visited[y][x+1]) q.push({{y, x+1}, d+1});
        if (x-1 >= 0 && map[y][x-1] == 1 && !visited[y][x-1]) q.push({{y, x-1}, d+1});
        if (y+1 < H && map[y+1][x] == 1 && !visited[y+1][x]) q.push({{y+1, x}, d+1});
        if (y-1 >= 0 && map[y-1][x] == 1 && !visited[y-1][x]) q.push({{y-1, x}, d+1});
    }
}

void solve() {
    cin>>H>>W;
    for (int y = 0; y < H; y++) {
        string tmp; cin>>tmp;
        for (int x = 0; x < W; x++) {
            if (tmp[x] == 'W') map[y][x] = 0;
            else map[y][x] = 1;
        }
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (map[y][x] == 1) {
                bfs(y, x);
            }
        }
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}