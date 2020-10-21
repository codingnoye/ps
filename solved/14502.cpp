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
const int MAX = 9;
int org[MAX][MAX];
int now[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

void dfs(int y, int x) {
    if (y<0 || N<=y || x<0 || M<=x) return;
    if (visited[y][x]) return;
    if (now[y][x] == 1) return; 
    visited[y][x] = true;
    now[y][x] = 2;
    dfs(y-1, x);
    dfs(y, x-1);
    dfs(y+1, x);
    dfs(y, x+1);
}

void solve() {
    cin>>N>>M;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cin>>org[y][x];
        }
    }
    int mx = 0;
    for (int y0=0; y0<N; y0++) {
        for (int x0=0; x0<M; x0++) {
            if (org[y0][x0] == 0) {
                for (int y1=y0; y1<N; y1++) {
                    for (int x1=(y1==y0)?x0+1:0; x1<M; x1++) {
                        if (org[y1][x1] == 0) {
                            for (int y2=y1; y2<N; y2++) {
                                for (int x2=(y2==y1)?x1+1:0; x2<M; x2++) {
                                    if (org[y2][x2] == 0) {
                    
                                        for (int y=0; y<N; y++)
                                            for (int x=0; x<M; x++) {
                                                visited[y][x] = false;
                                                now[y][x] = org[y][x];
                                                if ((y2==y && x2==x) || (y1==y && x1==x) || (y0==y && x0==x)) now[y][x] = 1;
                                            }
                                        for (int y=0; y<N; y++)
                                            for (int x=0; x<M; x++)
                                                if (visited[y][x] == false && now[y][x] == 2)
                                                    dfs(y, x);
                                        int cnt = 0;
                                        for (int y=0; y<N; y++)
                                            for (int x=0; x<M; x++)
                                                if (now[y][x] == 0) cnt++;
                                        mx = max(mx, cnt);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}