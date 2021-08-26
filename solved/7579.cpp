#include <iostream>
using namespace std;
typedef long long ll;

int item[101][2]; // c, m
ll bag[101][10001]; // bag[item][capacity]
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin>>N>>M;
    for (int i=0; i<=N; i++) {
        bag[0][i] = 0;
    }
    for (int i=1; i<=N; i++) {
        cin>>item[i][1];
    }
    for (int i=1; i<=N; i++) {
        cin>>item[i][0];
    }
    for (int i=1; i<=N; i++) {
        int c = item[i][0];
        int m = item[i][1];
        for (int j=0; j<c; j++) {
            bag[i][j] = bag[i-1][j];
        }
        for (int j=c; j<=10000; j++) {
            bag[i][j] = max(bag[i-1][j], bag[i-1][j-c]+m);
        }
    }
    for (int c=0; c<=10000; c++) {
        for (int n=0; n<=N; n++) {
            if (bag[n][c] >= M) {
                cout<<c<<'\n';
                return 0;
            }
        }
    } 
}