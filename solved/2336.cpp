#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
#define endl '\n'

typedef long long ll;

const int S = 1<<19;
// 담을 수 있는 원소의 개수 이상인 2^n인 수
// 1<<17 = 2^17 = 131072
// 1<<20 = 2^20 = 1048576

ll tree[2*S];
ll* leaf = tree+S;
// 모든 노드
// 리프 노드는 tree[S+i], i = [0, S) = leaf[i]
// 1이 루트

// 초기화
const int MAX = 987654321;
void init(bool clear = true) { // 최적화가 필요할 때, 값을 수동으로 넣은 후 clear = false
    if (clear)
        for (int i=S; i<2*S; i++) {
            tree[i] = MAX; // 변경할 부분 (기본값)
        }
    for (int i=S-1; i>=1; i--)  {
        tree[i] = min(tree[i*2], tree[i*2+1]); // 변경할 부분 (연산)
    }
}

// 업데이트
void update(int x, ll v) {
    int now = S+x;
    tree[now] = v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = min(tree[now*2], tree[now*2+1]); // 변경할 부분 (연산)
    }
}

// 구간 [s, e)에 대한 쿼리
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return MAX; // 변경할 부분 (기본값)
    } else {
        return min(query(s, e, node*2, start, end-size/2), query(s, e, node*2+1, start+size/2, end));  // 변경할 부분 (연산)
    }
}

void solve() {
    int N; cin>>N;
    vector<tuple<int, int, int>> students(N);
    for (int i=0; i<N; i++) {
        int v; cin>>v;
        get<0>(students[v-1]) = i+1;
    }
    for (int i=0; i<N; i++) {
        int v; cin>>v;
        get<1>(students[v-1]) = i+1;
    }
    for (int i=0; i<N; i++) {
        int v; cin>>v;
        get<2>(students[v-1]) = i+1;
    }
    sort(students.begin(), students.end());

    int res = 0;
    init();
    for (auto [a, b, c]: students) {
        if (query(1, b+1) > c)
            res++;
        update(b, c);
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}