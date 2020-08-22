#include <iostream>
using namespace std;
typedef unsigned long long ull;
const ull M = 1000000007ULL;
ull mul(ull x, ull y) {
    ull res = 1;
    while (y > 0) {
        if (y % 2) {
            res *= x;
            res %= M;
        }
        x *= x;
        x %= M;
        y /= 2;
    }
    return res;
}
int main() {
    ull N, K; cin>>N>>K;
    ull son = 1; // N!/(N-k)!
    ull mom = 1;
    for (ull i=N-K+1; i<=N; i++) {
        son *= i;
        son %= M;
    }
    for (ull i=1; i<=K; i++) {
        mom *= i;
        mom %= M;
    }
    cout<<(son*mul(mom, M-2))%M<<endl;
}