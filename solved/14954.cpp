#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

ll f(ll x) {
    ll res = 0;
    while (x>0) {
        ll y = x%10;
        res += y*y;
        x /= 10;
    }
    return res;
}

bool visited[800];

int main() {
    fastio;
    
    ll N; cin>>N;
    while (N != 1) {
        N = f(N);
        if (visited[N]) {
            cout<<"UNHAPPY"<<endl;
            return 0;
        }
        visited[N] = true;
    }
    cout<<"HAPPY"<<endl;
}