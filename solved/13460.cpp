#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
struct Move {
    Move() {}
    Move(ii r, ii b, int s) : rb(r), bb(b), S(s) {}
    ii rb;
    ii bb;
    int S;
};
const int moving[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};
int arr[10][10];
Move step(ii rb, ii bb, int tilt) {
    bool moved = true;
    int newy, newx;
    int res = 0;
    while (moved) {
        moved = false;
        newy = rb.first + moving[tilt][0];
        newx = rb.second + moving[tilt][1];
        while (arr[newy][newx]%4 == 0 && !(bb.first == newy && bb.second == newx)) {
            if (arr[newy][newx] == 4) {
                res = max(1, res);
                rb.first = -1;
                rb.second = -1;
                moved = false;
                break;
            }
            rb.first = newy;
            rb.second = newx;
            moved = true;
            newy = rb.first + moving[tilt][0];
            newx = rb.second + moving[tilt][1];
        }
        newy = bb.first + moving[tilt][0];
        newx = bb.second + moving[tilt][1];
        while (arr[newy][newx]%4 == 0 && !(rb.first == newy && rb.second == newx)) {
            if (arr[newy][newx] == 4) {
                res = 2;
                bb.first = -1;
                bb.second = -1;
                moved = false;
                break;
            }
            bb.first = newy;
            bb.second = newx;
            moved = true;
            newy = bb.first + moving[tilt][0];
            newx = bb.second + moving[tilt][1];
        }
    }
    return Move(rb, bb, res); // third is out. 0 is good, 1 is rb out, 2 is bb out
}
int main() {
    int N, M; cin>>N>>M;
    string tmp;
    ii rb, bb;
    for (int n=0; n<N; n++) {
        cin>>tmp;
        for (int m=0; m<M; m++) {
            switch (tmp.at(m)) {
                case '.': arr[n][m] = 0; break;
                case '#': arr[n][m] = 1; break;
                case 'R': arr[n][m] = 0; rb = ii(n, m); break;
                case 'B': arr[n][m] = 0; bb = ii(n, m); break;
                case 'O': arr[n][m] = 4; break;
            }
        }
    }
    queue<Move> q;
    q.push(Move(rb, bb, 0));
    while (!q.empty()) {
        Move now = q.front();
        Move res;
        q.pop();
        int i;
        for (i=0; i<4; i++) {
            res = step(now.rb, now.bb, i);
            //cout<<res.rb.first<<","<<res.rb.second<<" "<<res.bb.first<<","<<res.bb.second<<" "<<res.S<<" "<<now.S<<'\n';
            if (res.S==1) {
                cout<<now.S+1<<endl;
                break;
            } else if (res.S==2) {
                continue;
            } else if (now.S>=10) {
                cout<<-1<<endl;
                break;
            }
            q.push(Move(res.rb, res.bb, now.S+1));
        }
        if (i!=4) break;
    }
}