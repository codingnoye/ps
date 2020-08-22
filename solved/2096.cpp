#include <iostream>
#include <algorithm>
using namespace std;

int mindp[3];
int maxdp[3];
int minnew[3];
int maxnew[3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int inp[3];
    mindp[0] = 0; mindp[1] = 0; mindp[2] = 0;
    maxdp[0] = 0; maxdp[1] = 0; maxdp[2] = 0;
    for (int i=1; i<=n; i++) {
        cin>>inp[0]>>inp[1]>>inp[2];
        minnew[0] = min(mindp[0], mindp[1]) + inp[0];
        minnew[1] = min(min(mindp[0], mindp[1]), mindp[2]) + inp[1];
        minnew[2] = min(mindp[1], mindp[2]) + inp[2];
        maxnew[0] = max(maxdp[0], maxdp[1]) + inp[0];
        maxnew[1] = max(max(maxdp[0], maxdp[1]), maxdp[2]) + inp[1];
        maxnew[2] = max(maxdp[1], maxdp[2]) + inp[2];
        mindp[0] = minnew[0];
        mindp[1] = minnew[1];
        mindp[2] = minnew[2];
        maxdp[0] = maxnew[0];
        maxdp[1] = maxnew[1];
        maxdp[2] = maxnew[2];
    }
    cout<<max(max(maxdp[0], maxdp[1]), maxdp[2])<<" ";
    cout<<min(min(mindp[0], mindp[1]), mindp[2])<<endl;
}