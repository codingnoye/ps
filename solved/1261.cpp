#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
    int y;
    int x;
    point(int yy, int xx) : y(yy), x(xx) {};
};

int tries[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct state {
    point pos;
    int dist;
    point last;
    state(point n, int d, point l) : pos(n), dist(d), last(l) {};
};

struct cmp{
    bool operator()(state t, state u){
        return t.dist > u.dist;
    }
};

const int INF = 100001;

int map[100][100];
int dist[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int X, Y; cin>>X>>Y;
    string tmp;
    for (int y=0; y<Y; y++) {
        cin>>tmp;
        for (int x=0; x<X; x++) {
            map[y][x] = tmp.at(x)-'0';
            dist[y][x] = INF;
        }
    }
    priority_queue<state, vector<state>, cmp> pq;
    pq.push(state(point(0, 0), 0, point(0, 0)));
    while (!pq.empty()) {
        state now = pq.top(); pq.pop();
        //cout<<"x:"<<now.pos.x<<" y:"<<now.pos.y<<" dist:"<<now.dist<<endl;
        if (now.dist < dist[now.pos.y][now.pos.x]) {
            dist[now.pos.y][now.pos.x] = now.dist;
            for (int i=0; i<4; i++) {
                int tx = now.pos.x + tries[i][0];
                int ty = now.pos.y + tries[i][1];
                if (tx<0 || tx>=X || ty<0 || ty>=Y || (tx==now.last.x && ty==now.last.y)) continue;
                pq.push(state(point(ty, tx), now.dist+map[ty][tx], point(now.pos.y, now.pos.x))); 
            }
        }
    }
    cout<<dist[Y-1][X-1]<<endl;
}