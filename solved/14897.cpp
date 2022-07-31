#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
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

int arr[1001001];

Query q[1001001];
int offline_res[1001001];

int res = 0;

int cnts[1000001];

int K;

void append(int i, bool front) {
    if (cnts[arr[i]]++ == 0) res++;
}
void remove(int i, bool front) {
    if (cnts[arr[i]]-- == 1) res--;
}
int main() {
    fastio;
    
    int N; cin>>N;
    int sqrtN = 1000;
    // cout<<sqrtN<<endl;
    vector<int> comp;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
        comp.push_back(arr[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i=0; i<N; i++) {
        arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
    }
    int M; cin>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        q[i] = {(a-1)/sqrtN, a-1, b-1, i};
    }
    sort(q, q+M);
    int nows = 0;
    int nowe = -1;
    for (int i=0; i<M; i++) {
        auto [block, s, e, idx] = q[i];
        while (nows>s) {
            append(--nows, 1);
        }
        while (nowe<e) {
            append(++nowe, 0);
        }
        while (nows<s) {
            remove(nows++, 1);
        }
        while (nowe>e) {
            remove(nowe--, 0);
        }
        // cout<<block<<' '<<s<<' '<<e<<' '<<top<<endl;
        offline_res[idx] = res;
    }
    for (int i=0; i<M; i++) {
        cout<<offline_res[i]<<endl;
    }
}