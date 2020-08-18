#include <iostream>
#include <algorithm>
using namespace std;

int cost[1000][3] = {0};
int color[1000][3][3] = {0}; // color[n][choosed][startcolor]
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    for (int i=0; i<n; i++) cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    for (int c=0; c<3; c++) {
        for (int d=0; d<3; d++) color[0][d][c] = 1000001;
        color[0][c][c] = cost[0][c];
        for (int i=1; i<n; i++) {
            color[i][0][c] = min(color[i-1][1][c], color[i-1][2][c]) + cost[i][0];
            color[i][1][c] = min(color[i-1][2][c], color[i-1][0][c]) + cost[i][1];
            color[i][2][c] = min(color[i-1][0][c], color[i-1][1][c]) + cost[i][2];
        }
    }
    int m0, m1, m2;
    m0 = min(color[n-1][1][0], color[n-1][2][0]);
    m1 = min(color[n-1][0][1], color[n-1][2][1]);
    m2 = min(color[n-1][0][2], color[n-1][1][2]);
    cout<<min(min(m0, m1), m2)<<'\n';
}