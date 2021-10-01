#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef pair<int, pair<int, int>> trace; // {dist, {y, x}}

int arr[1001][1001];
int visited[1001][1001];
const int MAX = 987654321;
void solve() {
    int H, W; cin>>H>>W;
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            cin>>arr[y][x];
            visited[y][x] = MAX;
        }
    }
    priority_queue<trace, vector<trace>, greater<trace>> pq;
    visited[0][0] = arr[0][0];
    pq.push({arr[0][0], {0, 0}});
    if (arr[H-1][W-1] == -1 || arr[0][0] == -1) {
        cout<<-1<<endl;
        return;
    }
    while (!pq.empty()) {
        auto [dd, p] = pq.top();
        auto [y, x] = p;
        pq.pop();
        int d = visited[y][x];
        if (y == H-1 && x == W-1) break;
        if (y-1>=0 && arr[y-1][x]>=0 && visited[y-1][x] > d + arr[y-1][x]) {
            visited[y-1][x] = d + arr[y-1][x];
            pq.push({d + arr[y-1][x], {y-1, x}});
        }
        if (y+1<H && arr[y+1][x]>=0 && visited[y+1][x] > d + arr[y+1][x]) {
            visited[y+1][x] = d + arr[y+1][x];
            pq.push({d + arr[y+1][x], {y+1, x}});
        }
        if (x-1>=0 && arr[y][x-1]>=0 && visited[y][x-1] > d + arr[y][x-1]) {
            visited[y][x-1] = d + arr[y][x-1];
            pq.push({d + arr[y][x-1], {y, x-1}});
        }
        if (x+1<W && arr[y][x+1]>=0 && visited[y][x+1] > d + arr[y][x+1]) {
            visited[y][x+1] = d + arr[y][x+1];
            pq.push({d + arr[y][x+1], {y, x+1}});
        }
    }
    if (visited[H-1][W-1] == MAX) cout<<"-1"<<endl;
    else cout<<visited[H-1][W-1]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}