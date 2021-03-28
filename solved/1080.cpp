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

int arr[51][51];

void solve() {
    int N, M; cin>>N>>M;
    int cnt = 0;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            char c; cin>>c;
            arr[y][x] = (c=='0'?0:1);
        }
    }
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            char c; cin>>c;
            arr[y][x]^= (c=='0'?0:1);
        }
    }
    for (int y=0; y<N-2; y++) {
        for (int x=0; x<M-2; x++) {
            if (arr[y][x] == 1) {
                for (int yy=y; yy<y+3; yy++) {
                    for (int xx=x; xx<x+3; xx++) {
                        arr[yy][xx] = !arr[yy][xx];
                    }
                }
                cnt++;
            }
        }
    }
    bool trigger = false;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            if (arr[y][x] == 1) {
                trigger = true;
                break;
            }
        }
    }
    cout<<(trigger?-1:cnt)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}