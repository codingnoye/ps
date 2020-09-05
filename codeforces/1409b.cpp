#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull call(int a, int b, int mina, int minb, int n) {
    if (n==0 || (a==mina && b == minb)) return (ull)a*b;
    ull mn = 1000000000000000001ULL;
    if (a == mina) {

    } else if (a - n >= mina) {
        mn = min(call(a-n, b, mina, minb, n-n), mn);
    } else {
        mn = min(call(mina, b, mina, minb, n-(a-mina)), mn);
    }
    if (b == minb) {

    } else if (b - n >= minb) {
        mn = min(call(a, b-n, mina, minb, n-n), mn);
    } else {
        mn = min(call(a, minb, mina, minb, n-(b-minb)), mn);
    }
    return mn;
}

int main() {
    int T; cin>>T;
    while (T--) {
        int a, b, mina, minb, n; cin>>a>>b>>mina>>minb>>n;
        cout<<call(a, b, mina, minb, n)<<'\n';
    }
}