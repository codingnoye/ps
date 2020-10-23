#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int N, M, K;
int arr[101][101];

int dfs(int y, int x) {
    if (y<0 || y>=N || x<0 || x>=M) return 0;
    if (arr[y][x] == 1) return 0;
    arr[y][x] = 1;
    return 1 + dfs(y+1, x) + dfs(y-1, x) + dfs(y, x+1) + dfs(y, x-1);
}

void solve() {
    cin>>N>>M>>K;
    for (int i=0; i<K; i++) {
        int x0, y0, x1, y1; cin>>x0>>y0>>x1>>y1;
        for (int x=x0; x<x1; x++) {
            for (int y=y0; y<y1; y++) {
                arr[y][x] = 1;
            }
        }
    }
    vector<int> V;
    int cnt = 0;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            if (arr[y][x]==0) {
                V.push_back(dfs(y, x));
                cnt++;
            }
        }
    }
    sort(V.begin(), V.end());
    cout<<cnt<<endl;
    for (auto it=V.begin(); it<V.end(); it++) {
        cout<<(*it)<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}