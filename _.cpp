#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    int null;
    vector<int> arr(N);
    cin>>arr[0]>>arr[1];
    for (int i=1; i<N; i++) {
        cin>>null;
        cin>>arr[1+i];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}