#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ull, ull> puu;
typedef pair<ll, ll> pll;

const int MOD = 1000000007;

int arr[2001][2001];
int accX[2001];
int accY[2001];
int accXY[4004];
void solve() {
    int H, W; cin>>H>>W;
    for (int y=1; y<=H; y++) {
        string tmp; cin>>tmp;
        for (int x=1; x<=W; x++) {
            if (tmp.at(x-1)=='#') arr[y][x] = 1;
        }
    }
    for (int y=1; y<=H; y++) {
        for (int x=1; x<=W; x++) {
            if (arr[y][x]==1) {
                accY[y] = 0;
                accX[x] = 0;
                accXY[H-y+x] = 0;
                continue;
            }
            int now = accX[x];
            now %= MOD;
            now += accY[y];
            now %= MOD;
            now += accXY[H-y+x];
            now %= MOD;
            if (x==1 && y==1) {
                now = 1;
            }
            accX[x] += now;
            accX[x] %= MOD;
            accY[y] += now;
            accY[y] %= MOD;
            accXY[H-y+x] += now;
            accXY[H-y+x] %= MOD;

            if (x==W && y==H) cout<<now<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}