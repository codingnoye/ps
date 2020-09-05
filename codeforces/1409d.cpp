#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int sod(ull n) {
    string str = to_string(n);
    int sm = 0;
    for (char c: str) {
        sm += c-'0';
    }
    return sm;
}
int main() {
    int T; cin>>T;
    while (T--) {
        ull n; int s; cin>>n>>s;
        ull cnt = 0;
        ull nowlevel = 10;
        ull nown = n;
        while (true) {
            if (sod(nown) <= s) break;
            ull diff = nowlevel - (nown % nowlevel);
            nown += diff;
            cnt += diff;
            nowlevel *= 10;
        }
        cout<<cnt<<'\n';
    }
}