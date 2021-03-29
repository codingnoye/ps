#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

bool sieve[1100001];

void solve() {
    for (int i=2; i<1000001; i++) {
        if (!sieve[i]) for (int j=i*2; j<1000001; j+=i) sieve[j] = true;
    }
    while (true) {
        int x; cin>>x;
        if (x==0) break;
        bool outed = false;
        for (int i=3; i<=x/2; i++) {
            if (!sieve[i] && !sieve[x-i]) {
                cout<<x<<" = "<<i<<" + "<<(x-i)<<endl;
                outed = true;
                break;
            } 
        }
        if (!outed) cout<<"Goldbach's conjecture is wrong."<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}