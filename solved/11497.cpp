#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        vector<int> A(N);
        for (int i=0; i<N; i++) cin>>A[i];
        sort(A.begin(), A.end());
        deque<int> res;
        int ans = 0;
        for (int i=0; i<N; i++) {
            if (i%2 == 0) {
                if (i==0) res.push_back(A[i]);
                else {
                    ans = max(abs(res.back() - A[i]), ans);
                    res.push_back(A[i]);
                }
            } else {
                ans = max(abs(res.front() - A[i]), ans);
                res.push_front(A[i]);
            }
        }
        ans = max(abs(res.front() - res.back()), ans);

        cout<<ans<<endl;
    }
}