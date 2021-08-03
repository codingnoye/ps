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

int originGrid[31][31];
int newGrid[31][31];
int H, W;
void fill(int y, int x, int val, int target) {
    originGrid[y][x] = val;
    int ny, nx;

    ny = y-1;
    if (ny>=0 && originGrid[ny][x] == target)
        fill(ny, x, val, target);
    ny = y+1;
    if (ny<H && originGrid[ny][x] == target)
        fill(ny, x, val, target);
    nx = x-1;
    if (nx>=0 && originGrid[y][nx] == target)
        fill(y, nx, val, target);
    nx = x+1;
    if (nx<W && originGrid[y][nx] == target)
        fill(y, nx, val, target);
}
void solve() {
    cin>>H>>W;
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            cin>>originGrid[y][x];
        }
    }
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            cin>>newGrid[y][x];
        }
    }
    bool notFound = true;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (originGrid[y][x] != newGrid[y][x]) {
                int val = newGrid[y][x];
                notFound = false;
                fill(y, x, newGrid[y][x], originGrid[y][x]);
                break;
            }
        }
        if (!notFound) break;
    }
    if (notFound) {
        cout<<"YES"<<endl;
    } else {
        for(int y=0; y<H; y++) {
            for(int x=0; x<W; x++) {
                if (originGrid[y][x] != newGrid[y][x]) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}