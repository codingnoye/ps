#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[801][801];  

void solve() {
    int n, k; cin>>n>>k;
    
    multiset<int, greater<int>> now;
    int minm = 1000000000;

    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            cin>>arr[y][x];
            if (y<k && x<k) now.insert(arr[y][x]);
        }
    }
    int phase = 0;
    // 0 is going right, 1 is going left
    int x=0; int y=0;
    auto i = now.begin();
    int nth = (k*k)/2;
    advance(i, nth);
    while (true) {
        if (phase == 0) {
            for (x=0; x<n-k; x++) {
                i = now.begin();
                advance(i, nth);
                minm = min(*i, minm);
                for (int yy=y; yy<y+k; yy++) {
                    now.erase(now.lower_bound(arr[yy][x]));
                    now.insert(arr[yy][x+k]);
                }
            }
        } else {
            for (x=n-1; x>=k; x--) {
                i = now.begin();
                advance(i, nth);
                minm = min(*i, minm);
                for (int yy=y; yy<y+k; yy++) {
                    now.erase(now.lower_bound(arr[yy][x]));
                    now.insert(arr[yy][x-k]);
                }
            }
        }
        i = now.begin();
        advance(i, nth);
        minm = min(*i, minm);
        if (phase == 0)
            for (int xx=n-k; xx<n; xx++) {
                now.erase(now.lower_bound(arr[y][xx]));
                now.insert(arr[y+k][xx]);
            }
        else
            for (int xx=0; xx<k; xx++) {
                now.erase(now.lower_bound(arr[y][xx]));
                now.insert(arr[y+k][xx]);
            }
        y++;
        if (y == n-k+1) break;
        phase = (phase==0)?1:0;
    }
    cout<<minm<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}