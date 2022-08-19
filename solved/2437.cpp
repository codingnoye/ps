#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];
    sort(A.begin(), A.end());

    int now = 0;
    for (int a: A) {
        if (a-1 > now) {
            cout<<now+1<<endl;
            return 0;
        } else {
            now += a;
        }
    }
    cout<<now+1<<endl;
}