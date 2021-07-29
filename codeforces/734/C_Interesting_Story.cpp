#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> E;
void solve() {
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        A.clear(); B.clear(); C.clear(); D.clear(); E.clear();
        A.resize(n); B.resize(n); C.resize(n); D.resize(n); E.resize(n);
        for (int i = 0; i < n; i++) {
            string str; cin>>str;
            int cnt[5];
            int total = 0;
            cnt[0] = 0; cnt[1] = 0; cnt[2] = 0; cnt[3] = 0; cnt[4] = 0;
            for (char c: str) {
                cnt[c-'a']++;
                total++;
            }
            A[i] = 2*cnt[0] - total;
            B[i] = 2*cnt[1] - total;
            C[i] = 2*cnt[2] - total;
            D[i] = 2*cnt[3] - total;
            E[i] = 2*cnt[4] - total;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        sort(E.begin(), E.end());
        int ans = 0;
        int now = 0;
        int cnt = 0;
        for (auto n = A.rbegin(); n != A.rend(); n++) {
            now += *n;
            if (now <= 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
        now = 0;
        cnt = 0;
        for (auto n = B.rbegin(); n != B.rend(); n++) {
            now += *n;
            if (now <= 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
        now = 0;
        cnt = 0;
        for (auto n = C.rbegin(); n != C.rend(); n++) {
            now += *n;
            if (now <= 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
        now = 0;
        cnt = 0;
        for (auto n = D.rbegin(); n != D.rend(); n++) {
            now += *n;
            if (now <= 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
        now = 0;
        cnt = 0;
        for (auto n = E.rbegin(); n != E.rend(); n++) {
            now += *n;
            if (now <= 0) break;
            cnt++;
        }
        ans = max(ans, cnt);
        cout<<ans<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}