#include <string>
#include <queue>
#include <iostream>
using namespace std;
const int EMPTY = 0;
const int WALL = 1;
const int VISITED = 2;
const int VISITEDWALL = 3;
const int VISITEDAFTERBOMB = 4;
int map[1001][1001];
typedef pair<int, int> pos;
struct state {
    pos p;
    int d;
    bool bomb;
};
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    string tmp;
    for (int y=0; y<n; y++) {
        cin>>tmp;
        for (int x=0; x<m; x++) {
            map[y][x] = tmp.at(x)-48;
        }
    }
    int found = -1;
    queue<state> q;
    q.push(state {pos {0, 0}, 0, true});
    while (!q.empty()) {
        state now = q.front(); q.pop();
        //cout<<"pos: "<<now.p.first<<","<<now.p.second<<" d: "<<now.d<<endl;
        if (now.p.first == n-1 && now.p.second == m-1) {
            found = now.d+1;
            break;
        }
        if (now.bomb) {
            if (now.p.second != 0) {
                if (map[now.p.first][now.p.second-1]%4 == EMPTY) {
                    map[now.p.first][now.p.second-1] = VISITED;
                    q.push(state {pos {now.p.first, now.p.second-1}, now.d+1, true});
                } else if (map[now.p.first][now.p.second-1] == WALL) {
                    map[now.p.first][now.p.second-1] = VISITEDWALL;
                    q.push(state {pos {now.p.first, now.p.second-1}, now.d+1, false});
                }
            }
            if (now.p.second != m-1) {
                if (map[now.p.first][now.p.second+1]%4 == EMPTY) {
                    map[now.p.first][now.p.second+1] = VISITED;
                    q.push(state {pos {now.p.first, now.p.second+1}, now.d+1, true});
                } else if (map[now.p.first][now.p.second+1] == WALL) {
                    map[now.p.first][now.p.second+1] = VISITEDWALL;
                    q.push(state {pos {now.p.first, now.p.second+1}, now.d+1, false});
                }
            }
            if (now.p.first != 0) {
                if (map[now.p.first-1][now.p.second]%4 == EMPTY) {
                    map[now.p.first-1][now.p.second] = VISITED;
                    q.push(state {pos {now.p.first-1, now.p.second}, now.d+1, true});
                } else if (map[now.p.first-1][now.p.second] == WALL) {
                    map[now.p.first-1][now.p.second] = VISITEDWALL;
                    q.push(state {pos {now.p.first-1, now.p.second}, now.d+1, false});
                }
            }
            if (now.p.first != n-1) {
                if (map[now.p.first+1][now.p.second]%4 == EMPTY) {
                    map[now.p.first+1][now.p.second] = VISITED;
                    q.push(state {pos {now.p.first+1, now.p.second}, now.d+1, true});
                } else if (map[now.p.first+1][now.p.second] == WALL) {
                    map[now.p.first+1][now.p.second] = VISITEDWALL;
                    q.push(state {pos {now.p.first+1, now.p.second}, now.d+1, false});
                }
            }
        } else {
            if (now.p.second != 0) {
                if (map[now.p.first][now.p.second-1] == EMPTY) {
                    map[now.p.first][now.p.second-1] = VISITEDAFTERBOMB;
                    q.push(state {pos {now.p.first, now.p.second-1}, now.d+1, false});
                }
            }
            if (now.p.second != m-1) {
                if (map[now.p.first][now.p.second+1] == EMPTY) {
                    map[now.p.first][now.p.second+1] = VISITEDAFTERBOMB;
                    q.push(state {pos {now.p.first, now.p.second+1}, now.d+1, false});
                }
            }
            if (now.p.first != 0) {
                if (map[now.p.first-1][now.p.second] == EMPTY) {
                    map[now.p.first-1][now.p.second] = VISITEDAFTERBOMB;
                    q.push(state {pos {now.p.first-1, now.p.second}, now.d+1, false});
                }
            }
            if (now.p.first != n-1) {
                if (map[now.p.first+1][now.p.second] == EMPTY) {
                    map[now.p.first+1][now.p.second] = VISITEDAFTERBOMB;
                    q.push(state {pos {now.p.first+1, now.p.second}, now.d+1, false});
                }
            }
        }
    }
    cout<<found<<endl;
}