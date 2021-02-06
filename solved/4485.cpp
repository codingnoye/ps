#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#ifndef DEBUG
#define endl '\n'
#endif
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;
typedef pair<int, pair<int, int>> iii;

int arr[127][127];
int w[127][127];
bool visited[127][127];

void solve() {
    int T = 1;
    while (true) {
        int N; cin>>N;
        if (N==0) break;
        for (int y=0; y<N; y++) {
            for (int x=0; x<N; x++) {
                cin>>arr[y][x];
                w[y][x] = INT32_MAX;
                visited[y][x] = false;
            }
        }
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        w[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            iii now = pq.top();
            pq.pop();
            int v = now.first;
            int y = now.second.first;
            int x = now.second.second;

            //cout<<"y "<<y<<" x "<<x<<endl;
            if (visited[y][x]) continue;
            if (y==N-1 && x==N-1) {
                cout<<"Problem "<<(T++)<<": "<<(w[y][x] + arr[0][0])<<endl;
                break;
            }
            
            visited[y][x] = true;
            if (!(N<=x+1 || x+1<0 || y<0 || N<=y))
            if (!visited[y][x+1]) {
                w[y][x+1] = min(w[y][x+1], v + arr[y][x+1]);
                pq.push({w[y][x+1], {y, x+1}});
            }
            if (!(N<=x || x<0 || y+1<0 || N<=y+1))
            if (!visited[y+1][x]) {
                w[y+1][x] = min(w[y+1][x], v + arr[y+1][x]);
                pq.push({w[y+1][x], {y+1, x}});
            }
            if (!(N<=x-1 || x-1<0 || y<0 || N<=y))
            if (!visited[y][x-1]) {
                w[y][x-1] = min(w[y][x-1], v + arr[y][x-1]);
                pq.push({w[y][x-1], {y, x-1}});
            }
            if (!(N<=x || x<0 || y-1<0 || N<=y-1))
            if (!visited[y-1][x]) {
                w[y-1][x] = min(w[y-1][x], v + arr[y-1][x]);
                pq.push({w[y-1][x], {y-1, x}});
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