#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    for (int i=1; i<=sqrt(N); i++) {
        if (N%i != 0) continue;
        int a = i;
        int b = N/i;
        if ((a+b) % 2 == 0 && (b-a) % 2 == 0) {
            cout<<(a+b)/2<<' '<<(b-a)/2 <<endl;
            return 0;
        }
    }
    cout<<"impossible"<<endl;
}