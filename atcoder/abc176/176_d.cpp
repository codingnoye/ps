#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int EMPTY = -1;
const int WALL = -2;

int map[1001][1001];

bool isnear[1001][1001] = {false};
vector< vector<int> > graph;

bool visited[500001] = {false};

int warps[20][2] = {
    {-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2},
    {-1, -2}, {-1, -1}, {-1, 1}, {-1, 2},
    {0, -2}, {0, 2},
    {1, -2}, {1, -1}, {1, 1}, {1, 2},
    {2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2}
};

struct state {
    int now;
    int cost;
    state(int n, int c) : now(n), cost(c) {};
};

int H, W; 
bool placeable(int y, int x) {
    return (y>=0 && y<H && x>=0 && x<W);
}

void dfs(int y, int x, int num, set<int>& near) {
    if (!placeable(y, x)) return;
    if (map[y][x] != EMPTY) return;
    map[y][x] = num;
    for (int i=0; i<20; i++) {
        const int yy = y+warps[i][0];
        const int xx = x+warps[i][1];
        if (placeable(yy, xx))
            if (map[yy][xx] != num && map[yy][xx] >= 0) {
                near.insert(map[yy][xx]);
            }
    }
    dfs(y, x+1, num, near);
    dfs(y, x-1, num, near);
    dfs(y+1, x, num, near);
    dfs(y-1, x, num, near);
}

int main() {
    cin>>H>>W;
    int y, x; cin>>y>>x;
    y--; x--;
    int dy, dx; cin>>dy>>dx;
    dy--; dx--;
    for (int i=0; i<H; i++) {
        string tmp; cin>>tmp;
        for (int j=0; j<W; j++) {
            map[i][j] = (tmp.at(j)=='#'?WALL:EMPTY);
        }
    }
    // Numbering areas, store near areas to vector
    int nodes = 0;
    graph.resize(500001);
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            if (map[y][x] == EMPTY) {
                set<int> near;
                dfs(y, x, nodes, near);
                for (auto it=near.begin(); it!=near.end(); it++) {
                    graph[nodes].push_back(*it);
                    graph[*it].push_back(nodes);
                }
                nodes+=1;
            }
        }
    }
    queue<state> Q;
    Q.push(state(map[y][x], 0));
    int dest = map[dy][dx];
    while(!Q.empty()) {
        int now = Q.front().now;
        int cost = Q.front().cost;
        Q.pop();
        if (visited[now]) continue;
        if (now == dest) {
            cout<<cost<<endl;
            return 0;
        }
        visited[now] = true;
        for (int next: graph[now]) {
            Q.push(state(next, cost+1));
        }
    }
    cout<< -1 <<endl;
}