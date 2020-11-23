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

int arr[10001];
void solve() {
    int N; cin>>N;
    for (int i=0; i<N; i++) cin>>arr[i];
    int cap; cin>>cap;
    int l = 0;
    int r = 100001;
    while (l<r) {
        int mid = (l+r)/2;
        int sm = 0;
        for (int i=0; i<N; i++) {
            sm += min(mid, arr[i]);
        }
        if (cap>=sm) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    int res = (l+r)/2-1;
    int mx = 0;
    for (int i=0; i<N; i++) {
        mx = max(mx, min(res, arr[i]));
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}