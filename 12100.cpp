#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int N;
ii arr[7][22][22]; // val, last changed depth
int mx = 0;
void dfs(int depth, int dir) {
    if (depth==5) return;
    if (dir==0) { // up
        for (int x=1; x<=N; x++) {
            for (int y=1; y<=N; y++) {
                int newy = y;
                arr[depth+1][y][x].first = arr[depth][y][x].first;
                while (newy > 1 && arr[depth+1][newy-1][x].first == 0) {
                    arr[depth+1][newy-1][x].first = arr[depth+1][newy][x].first;
                    arr[depth+1][newy][x].first = 0;
                    arr[depth+1][newy][x].second = 0;
                    newy--;
                }
                if (arr[depth+1][newy-1][x].first == arr[depth+1][newy][x].first) {
                    if (arr[depth+1][newy-1][x].second <= depth) {
                        arr[depth+1][newy-1][x].first += 1;
                        arr[depth+1][newy-1][x].second = depth+1;
                        mx = max(mx, arr[depth+1][newy-1][x].first);
                        arr[depth+1][newy][x].first = 0;
                        arr[depth+1][newy][x].second = 0;
                    }
                }
            }
        }
    } else if (dir==1) { // down
        for (int x=1; x<=N; x++) {
            for (int y=N; y>=1; y--) {
                int newy = y;
                arr[depth+1][y][x].first = arr[depth][y][x].first;
                while (newy < N && arr[depth+1][newy+1][x].first == 0) {
                    arr[depth+1][newy+1][x].first = arr[depth+1][newy][x].first;
                    arr[depth+1][newy][x].first = 0;
                    arr[depth+1][newy][x].second = 0;
                    newy++;
                }
                if (arr[depth+1][newy+1][x].first == arr[depth+1][newy][x].first) {
                    if (arr[depth+1][newy+1][x].second <= depth) {
                        arr[depth+1][newy+1][x].first += 1;
                        arr[depth+1][newy+1][x].second = depth+1;
                        mx = max(mx, arr[depth+1][newy+1][x].first);
                        arr[depth+1][newy][x].first = 0;
                        arr[depth+1][newy][x].second = 0;
                    }
                }
            }
        }
    } else if (dir==2) { // left
        for (int y=1; y<=N; y++) {
            for (int x=1; x<=N; x++) {
                int newx = x;
                arr[depth+1][y][x].first = arr[depth][y][x].first;
                while (newx > 1 && arr[depth+1][y][newx-1].first == 0) {
                    arr[depth+1][y][newx-1].first = arr[depth+1][y][newx].first;
                    arr[depth+1][y][newx].first = 0;
                    arr[depth+1][y][newx].second = 0;
                    newx--;
                }
                if (arr[depth+1][y][newx-1].first == arr[depth+1][y][newx].first) {
                    if (arr[depth+1][y][newx-1].second <= depth) {
                        arr[depth+1][y][newx-1].first += 1;
                        arr[depth+1][y][newx-1].second = depth+1;
                        mx = max(mx, arr[depth+1][y][newx-1].first);
                        arr[depth+1][y][newx].first = 0;
                        arr[depth+1][y][newx].second = 0;
                    }
                }
            }
        }
    } else { // right
        for (int y=1; y<=N; y++) {
            for (int x=N; x>=1; x--) {
                int newx = x;
                arr[depth+1][y][x].first = arr[depth][y][x].first;
                while (newx < N && arr[depth+1][y][newx+1].first == 0) {
                    arr[depth+1][y][newx+1].first = arr[depth+1][y][newx].first;
                    arr[depth+1][y][newx].first = 0;
                    arr[depth+1][y][newx].second = 0;
                    newx++;
                }
                if (arr[depth+1][y][newx+1].first == arr[depth+1][y][newx].first) {
                    if (arr[depth+1][y][newx+1].second <= depth) {
                        arr[depth+1][y][newx+1].first += 1;
                        arr[depth+1][y][newx+1].second = depth+1;
                        mx = max(mx, arr[depth+1][y][newx+1].first);
                        arr[depth+1][y][newx].first = 0;
                        arr[depth+1][y][newx].second = 0;
                    }
                }
            }
        }
    }
    // cout<<"depth "<<depth<<" dir "<<dir<<endl;
    // for (int y=1; y<=N; y++) {
    //     for (int x=1; x<=N; x++) {
    //         cout<<arr[depth+1][y][x].first<<" ";
    //     }
    //     cout<<'\n';
    // }
    dfs(depth+1, 0);
    dfs(depth+1, 1);
    dfs(depth+1, 2);
    dfs(depth+1, 3);
}
int main() {
    cin>>N;
    int X, p;
    for (int x=1; x<=N; x++) arr[0][0][x] = make_pair(0, 0);
    for (int y=1; y<=N; y++) {
        arr[0][y][0] = make_pair(0, 0);
        for (int x=1; x<=N; x++) {
            cin>>X;
            p=0;
            for (;X>0;X>>=1) p++;
            mx = max(mx, p);
            arr[0][y][x] = make_pair(p, 0);
        }
        arr[0][y][N+1] = make_pair(0, 0);
    }
    for (int x=1; x<=N; x++) arr[0][N+1][x] = make_pair(0, 0);
    dfs(0, 0);
    dfs(0, 1);
    dfs(0, 2);
    dfs(0, 3);
    int res = 1;
    while (--mx) res<<=1;
    cout<<res<<endl;
}