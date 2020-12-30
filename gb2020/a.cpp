#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int arr[51];

void solve() {
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        set<int> s;
        int cnt = 0;
        for (int i=0; i<N; i++) cin>>arr[i];
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                int now = arr[j] - arr[i];
                if (s.find(now) == s.end()) {
                    s.insert(now);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}