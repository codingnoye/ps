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

int arr[2188][2188];
int res[3];
void rc(int sy, int sx, int ey, int ex) {
    int val = arr[sy][sx];
    bool trigger = false;
    for (int y=sy; y<ey; y++) {
        for (int x=sx; x<ex; x++) {
            if (val != arr[y][x]) {
                trigger = true;
                break;
            }
        }
    }
    
    if (trigger) {
        int dy = (ey-sy)/3;
        int dx = (ex-sx)/3;
        int res = 0;
        for (int y=0; y<3; y++)
            for (int x=0; x<3; x++)
                rc(sy + dy*y, sx + dx*x, sy + dy*(y+1), sx + dx*(x+1));
    } else {
        res[1+val]++;
    }
}

void solve() {
    int N; cin>>N;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    rc(0, 0, N, N);
    cout<<res[0]<<endl<<res[1]<<endl<<res[2]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}