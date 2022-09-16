#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;

    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];

    sort(all(A));

    int nowtime = 1;
    int endtime = 0;
    for (int i=N-1; i>=0; i--) {
        endtime = max(endtime, nowtime+A[i]);
        nowtime++;
    }
    cout<<endtime+1<<endl;
}