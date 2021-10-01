#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int N;
int map[101][101];

void dfsfill(int y, int x, int v) {
    if (map[y][x] != 1) return;
    map[y][x] = v;
    if (x-1 >= 0) dfsfill(y, x-1, v);
    if (x+1 < N) dfsfill(y, x+1, v);
    if (y-1 >= 0) dfsfill(y-1, x, v);
    if (y+1 < N) dfsfill(y+1, x, v);
}

void solve() {
    cin>>N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>map[i][j];
        }
    }
    int now = 2;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == 1) {
                dfsfill(i, j, now++);
            }
        }
    }
    int mn = 987654321;
    for (int y1=0; y1<N; y1++) {
        for (int x1=0; x1<N; x1++) {
            for (int y2=0; y2<N; y2++) {
                for (int x2=0; x2<N; x2++) {
                    if (map[y1][x1] == map[y2][x2] || map[y1][x1] <= 1 || map[y2][x2] <= 1) continue;
                    int hamdist = abs(y1-y2) + abs(x1-x2);
                    mn = min(hamdist, mn);
                }
            }
        }
    }
    cout<<(mn-1)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}