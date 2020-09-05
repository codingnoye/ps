#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int abs(int v) {
    return v<0?-v:v;
}
int main() {
    int T; cin>>T;
    while (T--) {
        int A, B; cin>>A>>B;
        int C = abs(A-B);
        int res = 0;
        res = C/10 + (C%10==0?0:1);
        cout<<res<<endl;
    }
}