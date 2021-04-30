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

int mindist[102][102];
int N, M, K;
bool can(int s, int e, int c, int k) {
    if (c==0 && k==0) return true;
    if (s>e) return false;
    int now = s;
    int cnt = 0;
    for (cnt=0; cnt<=c; cnt++) {
        if (cnt*now > k) break;
        if (can(s+1, e, c-cnt, k-cnt*now)) return true;
    }
    return false;
}
bool backtrack(int y, int x, int k) {
    if (y>N || x>M || k < 0) return false;
    if (y==N && x==M) {
        if (k==0) return true;
        else return false;
    }
    if (mindist[y][x] > k) return false;
    if (mindist[y][x] == k) return true;
    if (k < mindist[y][x]) return false;
    if (!can(min(x, y), max(x, y), N-y+M-x, k)) return false;
    return backtrack(y+1, x, k-x) || backtrack(y, x+1, k-y);
}
void solve() {
    int T; cin>>T;
    while (T--) {
        cin>>N>>M>>K;
        for (int y=0; y<102; y++) for (int x=0; x<102; x++) mindist[y][x] = 0;
        for (int y=0; y<102; y++) mindist[y][M+1] = 100000;
        for (int x=0; x<102; x++) mindist[N+1][x] = 100000;
        for (int y=N; y>=1; y--) for (int x=M; x>=1; x--) {
            if (y==N && x==M) continue;
            mindist[y][x] = min(mindist[y+1][x]+x, mindist[y][x+1]+y);
        }
        // for (int y=1; y<=N; y++) {
        //     for (int x=1; x<=M; x++) {
        //         cout<<mindist[y][x]<<' ';
        //     }
        //     cout<<endl;
        // }
        cout<<(backtrack(1, 1, K)?"YES":"NO")<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}