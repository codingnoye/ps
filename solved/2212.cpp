#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, K; cin>>N>>K;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];
    sort(all(A));

    ll total = A[N-1] - A[0];

    // N-1개의 구간 중, 가장 큰 K-1개의 구간만 없애기
    vector<int> ranges;
    for (int i=0; i<N-1; i++) {
        ranges.push_back(A[i+1] - A[i]);
    }
    sort(all(ranges));

    for (int i=0; i<min(N-1, K-1); i++) {
        total -= ranges[N-2-i];
    }
    cout<<total<<endl;
}