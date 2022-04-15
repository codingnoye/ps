#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int S = 1<<17;
// 담을 수 있는 원소의 개수 이상인 2^n인 수
// 1<<17 = 2^17 = 131072
// 1<<20 = 2^20 = 1048576

pair<ll, ll> tree[2*S];
// 모든 노드
// 리프 노드는 tree[S+i], i = [0, S) = leaf[i]
// 1이 루트

pair<ll, ll> get_top (pair<ll, ll> a, ll b) {
    vector<ll> tmp({a.first, a.second, b});
    sort(tmp.rbegin(), tmp.rend());
    return {tmp[0], tmp[1]};
}
pair<ll, ll> get_top (pair<ll, ll> a, pair<ll, ll> b) {
    vector<ll> tmp({a.first, a.second, b.first, b.second});
    sort(tmp.rbegin(), tmp.rend());
    return {tmp[0], tmp[1]};
}

// 초기화
void init(bool clear = true) { // 최적화가 필요할 때, 값을 수동으로 넣은 후 clear = false
    if (clear)
        for (int i=S; i<2*S; i++) {
            tree[i] = {0, 0}; // 변경할 부분 (기본값)
        }
    for (int i=S-1; i>=1; i--)  {
        tree[i] = get_top(tree[i*2], tree[i*2+1]);
    }
}

// 업데이트
void update(int x, ll v) {
    int now = S+x;
    tree[now] = {v, 0};
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = get_top(tree[now*2], tree[now*2+1]); // 변경할 부분 (연산)
    }
}

// 구간 [s, e)에 대한 쿼리
pair<ll, ll> query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return {0, 0}; // 변경할 부분 (기본값)
    } else {
        return get_top(query(s, e, node*2, start, end-size/2), query(s, e, node*2+1, start+size/2, end)); // 변경할 부분 (연산)
    }
}

void solve() {
    int N; cin>>N;
    init();
    for (int i=0; i<N; i++) {
        ll x; cin>>x;
        update(i, x);
    }
    int M; cin>>M;
    for (int i=0; i<M; i++) {
        ll a, b, c; cin>>a>>b>>c;
        if (a==1) {
            update(b-1, c);
        } else {
            pair<ll, ll> tmp = query(b-1, c);
            cout<<tmp.first+tmp.second<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}