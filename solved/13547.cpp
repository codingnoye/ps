#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Query {
    int block;
    int s;
    int e;
    int index;
    bool operator<(const Query &b) const {
        return block == b.block ? e < b.e : block < b.block;
    }
};

int arr[100001];

Query q[100001];
int res[100001];
int cnt[1000001];
void solve() {
    int N; cin>>N;
    int sqrtN = sqrt(N);
    for (int i=1; i<=N; i++) cin>>arr[i];
    int M; cin>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        q[i] = {(a-1)/sqrtN, a, b, i};
    }
    sort(q, q+M);
    int nows = 1;
    int nowe = 0;
    int nowcnt = 0;
    for (int i=0; i<M; i++) {
        auto [block, s, e, idx] = q[i];
        while (nows>s) {
            --nows;
            if (cnt[arr[nows]] == 0) nowcnt++;
            cnt[arr[nows]]++;
        }
        while (nowe<e) {
            ++nowe;
            if (cnt[arr[nowe]] == 0) nowcnt++;
            cnt[arr[nowe]]++;
        }
        while (nows<s) {
            cnt[arr[nows]]--;
            if (cnt[arr[nows]] == 0) nowcnt--;
            ++nows;
        }
        while (nowe>e) {
            cnt[arr[nowe]]--;
            if (cnt[arr[nowe]] == 0) nowcnt--;
            --nowe;
        }
        res[idx] = nowcnt;
    }
    for (int i=0; i<M; i++) {
        int r = res[i];
        cout<<r<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}