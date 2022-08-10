#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef long long ll;

const int S = 1<<12;
// 담을 수 있는 원소의 개수 이상인 2^n인 수
// 1<<17 = 2^17 = 131072
// 1<<20 = 2^20 = 1048576

struct node {
    ll lval;
    ll rval;
    ll val;
    ll all;
};

node tree[2*S];
node* leaf = tree+S;
// 모든 노드
// 리프 노드는 tree[S+i], i = [0, S) = leaf[i]
// 1이 루트

// 초기화
void init() { // 최적화가 필요할 때, 값을 수동으로 넣은 후 clear = false
    for (int i=0; i<2*S; i++) {
        tree[i] = {0, 0, 0, 0}; // 변경할 부분 (기본값)
    }
}

// 업데이트
void update(int x, ll v) {
    int i = S+x;
    auto [lval, rval, val, all] = tree[i];
    tree[i] = {lval+v, rval+v, val+v, all+v};
    while (i>1) { // 위 노드로 점점 이동하면서 갱신해주기
        i /= 2;
        auto& left = tree[i*2];
        auto& right = tree[i*2+1];
        tree[i] = {
            max(left.lval, left.all + right.lval),
            max(right.rval, right.all + left.rval),
            max(max(left.val, right.val), left.rval + right.lval),
            left.all + right.all
        };
    }
}

int main() {
    fastio;
    
    int N; cin>>N;
    vector<pair<pair<ll, ll>, ll>> A(N);
    vector<ll> xs, ys;
    for (int i=0; i<N; i++) {
        ll x, y, v; cin>>x>>y>>v;
        A[i] = {{x, y}, v};
        xs.push_back(x);
        ys.push_back(y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i=0; i<N; i++) {
        A[i].first.first = lower_bound(xs.begin(), xs.end(), A[i].first.first) - xs.begin();
        A[i].first.second = lower_bound(ys.begin(), ys.end(), A[i].first.second) - ys.begin();
    }
    
    ll maxearn = 0;
    sort(A.begin(), A.end());
    int XMAX = xs.size();
    for (int i=0; i<XMAX; i++) {
        init();
        int lastx = -1;
        for (auto& [coord, w]: A) {
            auto& [x, y] = coord;
            if (x < i) continue;

            if (lastx != x) {
                maxearn = max(maxearn, tree[1].val);
            }
            update(y, w);
            lastx = x;
        }
        maxearn = max(maxearn, tree[1].val);
    }
    cout<<maxearn<<endl;
}