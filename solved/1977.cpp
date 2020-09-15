#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int M, N; cin>>M>>N;
    int now = 0;
    int mn = 999999999;
    int sm = 0;
    while (true) {
        int nowsquare = now*now;
        now++;
        if (nowsquare < M) continue;
        if (nowsquare > N) break;
        sm += nowsquare;
        mn = min(mn, nowsquare);
    }
    if (mn == 999999999) cout<<-1<<'\n';
    else cout<<sm<<'\n'<<mn<<'\n';
}