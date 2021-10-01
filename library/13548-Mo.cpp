#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Query {
    int block;
    int s;
    int e;
    int idx;
    bool operator<(const Query &b) const {
        return block == b.block ? e < b.e : block < b.block;
    }
};

int arr[100001];

Query q[100001];
int offline_res[100001];
int cnt[100001];
int cnt_of_cnt[100001];

int res = 0;
void append(int i) {
    cnt_of_cnt[cnt[arr[i]]] -= 1;
    cnt[arr[i]]++;
    cnt_of_cnt[cnt[arr[i]]] += 1;
    res = max(res, cnt[arr[i]]);
}
void remove(int i) {
    cnt_of_cnt[cnt[arr[i]]] -= 1;
    cnt[arr[i]]--;
    cnt_of_cnt[cnt[arr[i]]] += 1;
    if (cnt_of_cnt[res] == 0) {
        for (int i=res-1; i>=0; i--) {
            if (cnt_of_cnt[i] > 0) {
                res = i;
                break;
            }
        }
    }
}
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
    cnt_of_cnt[0] = 100000;
    for (int i=0; i<M; i++) {
        auto [block, s, e, idx] = q[i];
        while (nows>s) {
            append(--nows);
        }
        while (nowe<e) {
            append(++nowe);
        }
        while (nows<s) {
            remove(nows++);
        }
        while (nowe>e) {
            remove(nowe--);
        }
        offline_res[idx] = res;
    }
    for (int i=0; i<M; i++) {
        cout<<offline_res[i]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}