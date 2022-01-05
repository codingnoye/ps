#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int arr[1001][1001];
void solve() {
    int H, W; cin>>H>>W;
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            cin>>arr[y][x];
        }
    }
    if (H%2 != 0) {
        // eat all, ㄹ
        for (int y=0; y<H; y++) {
            if (y%2 == 0) {
                for (int x=0; x<W-1; x++) {
                    cout<<"R";
                }
            } else {
                for (int x=0; x<W-1; x++) {
                    cout<<"L";
                }
            }
            if (y!=H-1) cout<<"D";
        }
    }
    else if (W%2 != 0) {
        // eat all, un
        for (int x=0; x<W; x++) {
            if (x%2 == 0) {
                for (int y=0; y<H-1; y++) {
                    cout<<"D";
                }
            } else {
                for (int y=0; y<H-1; y++) {
                    cout<<"U";
                }
            }
            if (x!=W-1) cout<<"R";
        }
    } else {
        int minval = 1001;
        pair<int, int> avoid = {0, 0};
        for (int y=0; y<H; y++) {
            for (int x=0; x<W; x++) {
                if ((x+y)%2 != 0 && minval > arr[y][x]) {
                    minval = arr[y][x];
                    avoid = {y, x};
                }
            }
        }
        // eat all, ㄹ with avoiding
        for (int y=0; y<H; y++) {
            if (y/2 < avoid.first/2) {
                if (y%2 == 0) {
                    for (int x=0; x<W-1; x++) {
                        cout<<"R";
                    }
                } else {
                    for (int x=0; x<W-1; x++) {
                        cout<<"L";
                    }
                }
                if (y!=H-1) cout<<"D";
            } else if (y/2 == avoid.first/2){
                bool down = true;
                for (int x=0; x<W-1; x++) {
                    if (down) {
                        if (x == avoid.second) {
                            cout<<"R";
                            continue;
                        }
                        cout<<"DR";
                        down = !down;
                    } else {
                        if ((x == avoid.second)) {
                            cout<<"R";
                            continue;
                        }
                        cout<<"UR";
                        down = !down;
                    }
                }
                y += 1;
                if (y!=H-1 && down) cout<<"D";
                if (y!=H-1) cout<<"D";
            } else {
                if (y%2 == 0) {
                    for (int x=0; x<W-1; x++) {
                        cout<<"L";
                    }
                } else {
                    for (int x=0; x<W-1; x++) {
                        cout<<"R";
                    }
                }
                if (y!=H-1) cout<<"D";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}