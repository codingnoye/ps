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

int arr[11][11];

void solve() {
    int H, W; cin>>H>>W;
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            char c; cin>>c;
            if (c=='.') arr[y][x] = 0;
            else arr[y][x] = 1;
        }
    }
    int res = 0;
    for (int y=0; y<H-1; y++) {
        // hor
        bool found = false;
        for (int x=0; x<W; x++) {
            if (arr[y][x] == 0 && arr[y+1][x] == 1) {
                if (!found) {
                    found = true;
                    res++;
                }
            } else {
                found = false;
            }
        }
    }
    for (int y=0; y<H-1; y++) {
        // hor
        bool found = false;
        for (int x=0; x<W; x++) {
            if (arr[y][x] == 1 && arr[y+1][x] == 0) {
                if (!found) {
                    found = true;
                    res++;
                }
            } else {
                found = false;
            }
        }
    }
    for (int x=0; x<W-1; x++) {
        // hor
        bool found = false;
        for (int y=0; y<H; y++) {
            if (arr[y][x] == 0 && arr[y][x+1] == 1) {
                if (!found) {
                    found = true;
                    res++;
                }
            } else {
                found = false;
            }
        }
    }
    for (int x=0; x<W-1; x++) {
        // hor
        bool found = false;
        for (int y=0; y<H; y++) {
            if (arr[y][x] == 1 && arr[y][x+1] == 0) {
                if (!found) {
                    found = true;
                    res++;
                }
            } else {
                found = false;
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}