#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll dp[1001][8][1001];
int arr[1001][3];
int N, K;
void solve() {
    cin>>N>>K;
    for (int y=0; y<N; y++) {
        for (int x=0; x<3; x++) {
            cin>>arr[y][x];
        }
    }
    for (int y=0; y<N; y++) {
        for (int k=K; k>0; k--) {
            for (int bf=0; bf<8; bf++) {
                dp[y][bf][k] = -987654321;
            }
        }
    }
    dp[0][0][K] = 0;
    for (int y=0; y<N; y++) {
        // prior = jobs in current line
        for (int bf=0; bf<8; bf++) {
            for (int k=K; k>=0; k--) {
                if (k>=1) {
                    if ((bf&0b011) == 0) dp[y][bf|0b011][k-1] = max(dp[y][bf|0b011][k-1], dp[y][bf][k] + arr[y][1] + arr[y][2]);
                    if ((bf&0b110) == 0) dp[y][bf|0b110][k-1] = max(dp[y][bf|0b110][k-1], dp[y][bf][k] + arr[y][0] + arr[y][1]);
                }
            }
        }
        
        for (int bf=0; bf<8; bf++) {
            for (int k=K; k>=0; k--) {
                dp[y+1][0][k] = max(dp[y+1][0][k], dp[y][bf][k]);
                if (k>=1) {
                    if ((bf&0b100) == 0) dp[y+1][0b100][k-1] = max(dp[y+1][0b100][k-1], dp[y][bf][k] + arr[y][0] + arr[y+1][0]);
                    if ((bf&0b010) == 0) dp[y+1][0b010][k-1] = max(dp[y+1][0b010][k-1], dp[y][bf][k] + arr[y][1] + arr[y+1][1]);
                    if ((bf&0b001) == 0) dp[y+1][0b001][k-1] = max(dp[y+1][0b001][k-1], dp[y][bf][k] + arr[y][2] + arr[y+1][2]);
                }
                if (k>=2) {
                    if ((bf&0b110) == 0) dp[y+1][0b110][k-2] = max(dp[y+1][0b110][k-2], dp[y][bf][k] + arr[y][0] + arr[y+1][0] + arr[y][1] + arr[y+1][1]);
                    if ((bf&0b011) == 0) dp[y+1][0b011][k-2] = max(dp[y+1][0b011][k-2], dp[y][bf][k] + arr[y][1] + arr[y+1][1] + arr[y][2] + arr[y+1][2]);
                    if ((bf&0b101) == 0) dp[y+1][0b101][k-2] = max(dp[y+1][0b101][k-2], dp[y][bf][k] + arr[y][0] + arr[y+1][0] + arr[y][2] + arr[y+1][2]);
                }
                if (k>=3) {
                    if ((bf&0b111) == 0) dp[y+1][0b111][k-3] = max(dp[y+1][0b111][k-3], dp[y][bf][k] + arr[y][0] + arr[y+1][0] + arr[y][1] + arr[y+1][1] + arr[y][2] + arr[y+1][2]);
                }
            }
        }
    }
    cout<<dp[N][0][0]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}