#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define endl '\n'
typedef long long ll;

int arr[1001][1001];
bool keep[1001][1001];
void solve() {
    int H, W; cin>>H>>W;
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            cin>>arr[y][x];
        }
    }
    for (int y=0; y<H; y++) {
        int nowmax = -1;
        pair<int, int> maxcoor = {0, 0};
        for (int x=0; x<W; x++) {
            if (arr[y][x] > nowmax) {
                maxcoor = {y, x};
                nowmax = arr[y][x];
            }
        }
        keep[maxcoor.first][maxcoor.second] = true;
    }
    for (int x=0; x<W; x++) {
        int nowmax = -1;
        pair<int, int> maxcoor = {0, 0};
        for (int y=0; y<H; y++) {
            if (arr[y][x] > nowmax) {
                maxcoor = {y, x};
                nowmax = arr[y][x];
            }
        }
        keep[maxcoor.first][maxcoor.second] = true;
    }
    ll res = 0;
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            if (!keep[y][x])
                res += arr[y][x];
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