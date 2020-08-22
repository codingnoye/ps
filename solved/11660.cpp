#include <iostream>
using namespace std;
int n, m;
int map[1025][1025];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    int linesum, tmp;
    for (int x=0; x<=n; x++) {
        map[0][x] = 0;
    }
    for (int y=1; y<=n; y++) {
        linesum = 0;
        map[y][0] = 0;
        for (int x=1; x<=n; x++) {
            cin>>tmp;
            linesum += tmp; 
            map[y][x] = map[y-1][x] + linesum;
        }
    }
    int x1, y1, x2, y2, res;
    for (int i=0; i<m; i++) {
        cin>>y1>>x1>>y2>>x2;
        res = map[y2][x2] - map[y1-1][x2] - map[y2][x1-1] + map[y1-1][x1-1];
        cout<<res<<'\n';
    }
}