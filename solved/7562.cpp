#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;

bool visited[301][301];
void solve() {
    int T; cin>>T;
    while (T--) {
        int L; cin>>L;
        int kx, ky; cin>>kx>>ky;
        int dx, dy; cin>>dx>>dy;

        for (int i=0; i<L; i++) for (int j=0; j<L; j++) visited[i][j] = false;

        queue<pair<ii, int>> q;
        q.push(make_pair(ii{kx, ky}, 0));
        while (!q.empty()) {
            int nx = q.front().first.first;
            int ny = q.front().first.second;
            int d = q.front().second;
            q.pop();
            if (nx<0 || nx>=L || ny<0 || ny>=L) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if (nx==dx && ny==dy) {
                cout<<d<<endl;
                break;
            }
            q.push(make_pair(ii{nx+1, ny+2}, d+1));
            q.push(make_pair(ii{nx+1, ny-2}, d+1));
            q.push(make_pair(ii{nx-1, ny+2}, d+1));
            q.push(make_pair(ii{nx-1, ny-2}, d+1));
            q.push(make_pair(ii{nx+2, ny+1}, d+1));
            q.push(make_pair(ii{nx+2, ny-1}, d+1));
            q.push(make_pair(ii{nx-2, ny+1}, d+1));
            q.push(make_pair(ii{nx-2, ny-1}, d+1));
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}