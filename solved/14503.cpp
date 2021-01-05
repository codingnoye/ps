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

const int EMPTY = 0, WALL = 1, CLEAN = 2;
int N, M;
int arr[51][51];
int cleaned = 0;
int mv[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void clean(int r, int c) {
    arr[r][c] = CLEAN;
    cleaned++;
}
void run(int r, int c, int d) {
    bool worked = false;
    int newd = d;
    for (int i=0; i<4; i++) {
        newd = (newd+3) % 4;
        int newr = r+mv[newd][0];
        int newc = c+mv[newd][1];
        if (arr[newr][newc] == EMPTY) {
            clean(newr, newc);
            run(newr, newc, newd);
            worked = true;
            break;
        }
    }
    if (!worked) {
        if (arr[r-mv[d][0]][c-mv[d][1]] != WALL) {
            run(r-mv[d][0], c-mv[d][1], d);
        }
    }
}

void solve() {
    cin>>N>>M;
    int r, c, d; cin>>r>>c>>d;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cin>>arr[y][x];
        }
    }
    clean(r, c);
    run(r, c, d);
    cout<<cleaned<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}