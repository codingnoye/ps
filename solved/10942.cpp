#include <iostream>
using namespace std;

int arr[2001] = {0};
int dp[2001][2001];
bool isMirror(int a, int b, int size) {
    bool equal = true;
    for (int i=0; i<size; i++) {
        if (arr[a-i]!=arr[b+i]) {
            equal = false;
            break;
        }
    }
    return equal;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    for (int i=1; i<=N; i++) {
        cin>>arr[i];
        dp[1][i] = 1;
        if (arr[i] == arr[i-1]) dp[2][i-1] = 1;
    }
    for (int j=2; j<=N; j+=1) {
        int size = j/2;
        for (int i=0; i<=N-j+1; i++) {
            if (j%2==1) {
                if (dp[j-2][i+1])
                    if (arr[i] == arr[i+size+size]) {
                        dp[j][i] = 1;
                    }
            } else {
                if (dp[j-2][i+1])
                    if (arr[i] == arr[i+size+size-1]) {
                        dp[j][i] = 1;
                    }
            }
        }
    }
    int M; cin>>M;
    while (M--) {
        int s, e; cin>>s>>e;
        cout<<dp[e-s+1][s]<<'\n';
    }
}