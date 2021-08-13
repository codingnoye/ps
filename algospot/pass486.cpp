#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int sieve[10000001];
void solve() {
    int C; cin>>C;
    
    for (int i=1; i<10000001; i++) {
        for (int j=i; j<10000001; j+=i) {
            sieve[j]++;
        }
    }
    while(C--) {
        int n, lo, hi; cin>>n>>lo>>hi;
        int cnt = 0;
        for (int i=lo; i<=hi; i++) {
            if (sieve[i] == n) { 
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}