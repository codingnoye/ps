#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
 
bool sieve[100001];
bool sieve2[100001];
vector<int> sosus;
 
int N, M;
 
void boonhae_and_sieve2(int x) {
 
}
int res[100001];
int reslen = 0;
void solve() {
    cin>>N>>M;
 
    for (int i=2; i<=100000; i++) {
        if (!sieve[i]) {
            sosus.push_back(i);
            for (int j=i*2; j<=100000; j+=i) {
                sieve[j] = true;
            }
        }
    }
 
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        for (int sosu: sosus) {
            if (x%sosu == 0) {
                if (sieve2[sosu] == false) {
                    for (int j=sosu; j<=100000; j+=sosu) {
                        sieve2[j] = true;
                    }
                }
            }
            if (x < sosu) break;
        }
    }
    for (int i=1; i<=M; i++) {
        if (!sieve2[i]) {
            res[reslen++] = i;
        }   
    }
    cout<<reslen<<endl;
    for (int i=0; i<reslen; i++) cout<<res[i]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}