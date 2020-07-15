#include <iostream>
using namespace std;

int item[101][2]; // w, v
int bag[101][100001]; // bag[item][capacity]
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin>>n>>k;
    for (int i=0; i<=k; i++) bag[0][i] = 0;
    for (int i=1; i<=n; i++) {
        cin>>item[i][0]>>item[i][1];
    };
    int w, v;
    for (int i=1; i<=n; i++) {
        w = item[i][0];
        v = item[i][1];
        for (int j=0; j<w; j++) {
            bag[i][j] = bag[i-1][j];
        }
        for (int j=w; j<=k; j++) {
            bag[i][j] = max(bag[i-1][j], bag[i-1][j-w]+v);
        }
    }
    cout<<bag[n][k]<<endl;    
}