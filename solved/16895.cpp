#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    vector<ll> arr(N);
    ll gr = 0;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
        gr ^= arr[i];
    }
    if (gr) {
        int cnt;
        for (int i=0; i<N; i++) {
            if (arr[i] > (gr ^ arr[i])) cnt++;
        }
        cout<<cnt<<endl;
    } else {
        cout<<0<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}