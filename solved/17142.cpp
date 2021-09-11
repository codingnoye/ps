#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
typedef long long ll;

int N, M, V;
int originMap[51][51];
int nowMap[51][51];
vector<pair<int, int>> virusPoints;
bool perm[11];
int mintime = 987654321;
void calculateTime () {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            nowMap[y][x] = originMap[y][x];
        }
    }
    
    int totalTime = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < V; i++) {
        if (perm[i]) {
            q.push({{virusPoints[i].first, virusPoints[i].second}, 0});
        } else {
            nowMap[virusPoints[i].first][virusPoints[i].second] = 3;
        }
    }
    int cntZero = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (nowMap[y][x] == 0) cntZero++;
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        auto [y, x] = cur.first;
        q.pop();
        if (nowMap[y][x] == 2) continue;
        if (nowMap[y][x] == 0) cntZero--;
        nowMap[y][x] = 2;
        totalTime = max(totalTime, cur.second);
        if (cntZero == 0) break;
        if (y-1 >= 0 && nowMap[y - 1][x]%3 == 0) q.push({{y-1, x}, cur.second + 1});
        if (y+1 < N && nowMap[y + 1][x]%3 == 0) q.push({{y+1, x}, cur.second + 1});
        if (x-1 >= 0 && nowMap[y][x - 1]%3 == 0) q.push({{y, x-1}, cur.second + 1});
        if (x+1 < N && nowMap[y][x + 1]%3 == 0) q.push({{y, x+1}, cur.second + 1});
    }
    bool allFilled = true;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (nowMap[y][x] == 0) allFilled = false;
        }
    }
    // for (bool b : perm) {cout<<b<<' ';}
    // cout<<endl;
    // cout<<totalTime<<' '<<allFilled<<endl;
    if (allFilled) {
        mintime = min(mintime, totalTime);
    }
}

void permutation(int now, int picked) {
    if (picked == M) {
        calculateTime();
    } else {
        if (now == V) return;
        perm[now] = true;
        permutation(now + 1, picked + 1);
        perm[now] = false;
        permutation(now + 1, picked);
    }
}

void solve() {
    cin>>N>>M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int v; cin>>v;
            if (v == 2) {
                virusPoints.push_back({y, x});
            } else {
                originMap[y][x] = v;
            }
        }
    }
    V = virusPoints.size();

    permutation(0, 0);
    if (mintime == 987654321) {
        cout<<-1<<endl;
    } else {
        cout<<mintime<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}