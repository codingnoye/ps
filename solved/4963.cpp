#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int W, H;
int map[51][51];

void dfs(int x, int y) {
    if (x<0 || x>=W || y<0 || y>=H) return;
    if (map[y][x] == 0) return;
    map[y][x] = 0;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x-1, y-1);
    dfs(x+1, y-1);
    dfs(x-1, y+1);
    dfs(x+1, y+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin>>W>>H;
        if (!(W||H)) break;
        for (int h=0; h<H; h++) {
            for (int w=0; w<W; w++) {
                cin>>map[h][w];
            }
        }
        int count = 0;
        for (int h=0; h<H; h++) {
            for (int w=0; w<W; w++) {
                if (map[h][w]) {
                    dfs(w, h);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}