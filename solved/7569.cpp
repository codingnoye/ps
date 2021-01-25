#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

struct xyzn {
    int x;
    int y;
    int z;
    int n;
};

int X, Y, Z;
int visited[101][101][101];
int arr[101][101][101];

bool valid(xyzn p) {
    return !(p.x<0 || X<=p.x || p.y<0 || Y<=p.y || p.z<0 || Z<=p.z) && arr[p.x][p.y][p.z] == 0 && !visited[p.x][p.y][p.z];
}
void solve() {
    cin>>X>>Y>>Z;
    for (int z=0; z<Z; z++)
        for (int y=0; y<Y; y++)
            for (int x=0; x<X; x++)
                cin>>arr[x][y][z];
    queue<xyzn> q;
    for (int x=0; x<X; x++)
        for (int y=0; y<Y; y++)
            for (int z=0; z<Z; z++)
                if (arr[x][y][z] == 1)
                    q.push({x, y, z, 1});
    while (!q.empty()) {
        xyzn now = q.front();
        q.pop();
        if (arr[now.x][now.y][now.z] < now.n && arr[now.x][now.y][now.z] != 0) continue;
        arr[now.x][now.y][now.z] = now.n;
        xyzn p;
        p = {now.x+1, now.y, now.z, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
        p = {now.x-1, now.y, now.z, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
        p = {now.x, now.y+1, now.z, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
        p = {now.x, now.y-1, now.z, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
        p = {now.x, now.y, now.z+1, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
        p = {now.x, now.y, now.z-1, now.n+1};
        if (valid(p)) {
            q.push(p);
            visited[p.x][p.y][p.z] = true;
        }
    }
    bool all = true;
    int mx = -1;
    for (int z=0; z<Z; z++) {
        for (int y=0; y<Y; y++) {
            for (int x=0; x<X; x++) {
                if (arr[x][y][z] == 0) {
                   all = false;
                   break;
                }
                mx = max(mx, arr[x][y][z]);
            }
        }
    }
    if (!all) {
        cout<<"-1"<<endl;
    } else {
        cout<<(mx-1)<<endl;
    }
                
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}