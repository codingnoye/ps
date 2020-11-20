#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;

struct point{
    int x;
    int y;
};

vector<point> homes;
vector<point> chickens;
vector<vector<int>> dists;
int mabs(int x) {
    if (x<0) return -x;
    return x;
}
int dist(point a, point b) {
    return mabs(a.x-b.x) + mabs(a.y-b.y);
}
int N, M;
int record[13];
int res = 999999999;
int mins[101][13];
void end() {
    int total = 0;
    for (int h=0; h<homes.size(); h++) {
        int mn = 999999999;
        for (int r=0; r<M; r++) {
            mn = min(mn, dists[h][record[r]]);
        }
        total += mn;
    }
    res = min(res, total);
}
void comb(int s, int e, int d) {
    if (d==M) end();
    if (s>=e) return;
    else {
        record[d] = s;
        comb(s+1, e, d+1);

        comb(s+1, e, d);
    }
}
void solve() {
    cin>>N>>M;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            int n; cin>>n;
            if (n==1) homes.push_back({x, y});
            else if (n==2) chickens.push_back({x, y});
        }
    }
    dists.resize(homes.size());
    for (int c=0; c<chickens.size(); c++) {
        for (int h=0; h<homes.size(); h++) {
            dists[h].push_back(dist(chickens[c], homes[h]));
        }
    }
    comb(0, chickens.size(), 0);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}