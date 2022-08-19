#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
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
void init(int n, bool clear = true) { // 최적화가 필요할 때, 값을 수동으로 넣은 후 clear = false
    if (clear) {
        for (int i=S; i<S+n; i++) {
            tree[i] = 1; // 변경할 부분 (기본값)
        }
        for (int i=S+n; i<2*S; i++) {
            tree[i] = 0; // 변경할 부분 (기본값)
        }
    }
    for (int i=S-1; i>=1; i--)  {
        tree[i] = tree[i*2] + tree[i*2+1]; // 변경할 부분 (연산)
    }
}

// 업데이트
void update(int x, ll v) {
    int now = S+x;
    tree[now] = v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = tree[now*2] + tree[now*2+1]; // 변경할 부분 (연산)
    }
}

// 구간 [s, e)에 대한 쿼리
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0; // 변경할 부분 (기본값)
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end); // 변경할 부분 (연산)
    }
}

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        init(N);
        vector<int> A(N);
        vector<vector<int>> indices(N+1); // 반번호 -> vec<위치>

        for (int i=0; i<N; i++) {
            cin>>A[i];
            indices[A[i]].push_back(i);
        }
        for (int i=1; i<=N; i++) {
            sort(indices[i].begin(), indices[i].end());
        }
        ll res = 0;
        for (int left_idx=0; left_idx<N; left_idx++) {
            int val = A[left_idx];
            int right_idx = indices[val].back();
            indices[val].pop_back();
            res += query(left_idx, right_idx);
            update(right_idx, 0);
        }
        cout<<"Case #"<<t<<endl<<res<<endl;
    }
}