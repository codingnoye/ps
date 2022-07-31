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

int arr[101001];

Query q[101001];
int offline_res[101001];
list<int> deq[1001001];

int res = 0; // append와 remove과정에서 답이 담길 변수

int top = 0;
int cnts[10001001] = {10001001};

int cumsum[1001001];

int K;

void append(int i, bool front) {
    int val = cumsum[i];
    int oldlen = (deq[val].size()>=2) ? deq[val].back() - deq[val].front() : 0;
    if (front)
        deq[val].push_front(i);
    else
        deq[val].push_back(i);
    int newlen = (deq[val].size()>=2) ? deq[val].back() - deq[val].front() : 0;

    cnts[oldlen]--;
    cnts[newlen]++;

    if (newlen > top) top = newlen;
}
void remove(int i, bool front) {
    int val = cumsum[i];
    int oldlen = (deq[val].size()>=2) ? deq[val].back() - deq[val].front() : 0;
    if (front)
        deq[val].pop_front();
    else
        deq[val].pop_back();
    int newlen = (deq[val].size()>=2) ? deq[val].back() - deq[val].front() : 0;

    cnts[oldlen]--;
    cnts[newlen]++;

    if (oldlen == top && cnts[top] == 0) {
        while (cnts[top] == 0) top--;
    }
}
int main() {
    fastio;
    
    int N; cin>>N>>K;
    int sqrtN = 300;
    // cout<<sqrtN<<endl;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
        arr[i] %= K;
    }
    for (int i=0; i<N; i++) {
        cumsum[i+1] = cumsum[i] + arr[i];
        cumsum[i+1] %= K;
    }
    int M; cin>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        q[i] = {(a-1)/sqrtN, a-1, b, i};
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
        offline_res[idx] = top;
    }
    for (int i=0; i<M; i++) {
        cout<<offline_res[i]<<endl;
    }
}