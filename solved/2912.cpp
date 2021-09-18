#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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

// 노드 번호: 0~N-1
int S; // 트리 종단 노드의 개수 
int H; // 트리의 높이 (노드 1개 -> 1, 노드 7개 -> 3, ...)
pair<int, int> tree[40000]; // 최대 크기는 가능한 최대 노드의 4배로 잡으면 안전

void init(int n) {
    H = 0;
    for (S=1; S<n; S<<=1) {
        H++;
    }
    for (int i=0; i<2*S; i++) {
        tree[i] = {0, i-S}; // 구간합이므로 기본값은 0
    }
}

void build () {
    for (int i=S-1; i>=1; i--)  {
        tree[i] = max(tree[i*2], tree[i*2+1]); // 구간합이므로 더하기
    }
}

void update(int x, int v) {
    int now = S+x;
    tree[now].first += v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = max(tree[now*2], tree[now*2+1]); // 구간합이므로 더하기
    }
}

// 구간: [s, e)
// node: 현재 노드, start, end: 현재 노드의 범위
pair<int, int> query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return {-1, -1};
    } else {
        return max(query(s, e, node*2, start, end-size/2), query(s, e, node*2+1, start+size/2, end));
    }
}

int arr[300001];
int cnt[10001];

Query q[10001];
pair<bool, int> res[10001];

void solve() {
    int N, C; cin>>N>>C;
    int sqrtN = sqrt(N);
    for (int i=1; i<=N; i++) cin>>arr[i];
    int M; cin>>M;
    init(M);
    build();
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        q[i] = {(a-1)/sqrtN, a, b, i};
    }
    sort(q, q+M);
    int nows = 1;
    int nowe = 0;
    for (int i=0; i<M; i++) {
        auto [block, s, e, idx] = q[i];
        while (nows<s) {
            cnt[arr[nows++]] -= 1;
        }
        while (nows>s) {
            cnt[arr[--nows]] += 1;
        }
        while (nowe<e) {
            cnt[arr[++nowe]] += 1;
        }
        while (nowe>e) {
            cnt[arr[nowe--]] -= 1;
        }
        for (int j=0; j<10001; j++) {
            if (cnt[j]*2 > (nowe - nows + 1)) {
                res[idx] = {true, j};
                break;
            } else {
                res[idx] = {false, 0};
            }
        }
    }
    for (int i=0; i<M; i++) {
        auto r = res[i];
        if (r.first) cout<<"yes "<<r.second<<endl;
        else cout<<"no"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}