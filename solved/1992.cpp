#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[64][64];

string recc(int sx, int sy, int ex, int ey) {
    int d = (ex - sx)/2;
    int val = arr[sy][sx];
    bool trigger = true;
    for (int y=sy; y<ey; y++) {
        for (int x=sx; x<ex; x++) {
            if (val != arr[y][x]) {
                trigger = false;
                break;
            }
        }
    }
    if (trigger) return to_string(val);
    return "(" + recc(sx, sy, sx+d, sy+d) + recc(sx+d, sy, ex, sy+d) + recc(sx, sy+d, sx+d, ey) + recc(sx+d, sy+d, ex, ey) + ")";
}

void solve() {
    int N; cin>>N;
    for (int y=0; y<N; y++) {
        string tmp; cin>>tmp;
        for (int x=0; x<N; x++) {
            arr[y][x] = tmp.at(x) - '0';
        }
    }
    cout<<recc(0, 0, N, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}