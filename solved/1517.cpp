#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define endl '\n'

typedef long long ll;

// 노드 번호: 0~N-1
int S; // 트리 종단 노드의 개수 
int H; // 트리의 높이 (노드 1개 -> 1, 노드 7개 -> 3, ...)
ll tree[2000000]; // 최대 크기는 가능한 최대 노드의 4배로 잡으면 안전

void init(int n) {
    H = 0;
    for (S=1; S<n; S<<=1) {
        H++;
    }
    for (int i=0; i<2*S; i++) {
        tree[i] = 0; // 구간합이므로 기본값은 0
    }
}

void build () {
    for (int i=S-1; i>=1; i--)  {
        tree[i] = tree[i*2] + tree[i*2+1]; // 구간합이므로 더하기
    }
}

void update(int x, ll v) {
    int now = S+x;
    tree[now] = v;
    while (now>1) { // 위 노드로 점점 이동하면서 갱신해주기
        now /= 2;
        tree[now] = tree[now*2] + tree[now*2+1]; // 구간합이므로 더하기
    }
}

// 구간: [s, e)
// node: 현재 노드, start, end: 현재 노드의 범위
ll query(int s, int e, int node=1, int start=0, int end=S) {
    int size = end - start;
    if (s<=start && end<=e) {
        return tree[node];
    } else if (e<=start || end<=s) {
        return 0;
    } else {
        return query(s, e, node*2, start, end-size/2) + query(s, e, node*2+1, start+size/2, end);
    }
}

vector<int> comp(vector<int>& points) {
    set<int> sorted_set;
    map<int, int> mapping;
    int i = 0;

    for (int p: points)
        sorted_set.insert(p);
    for (int p: sorted_set)  
        mapping[p] = i++;
    
    vector<int> result;
    for (int p: points)
        result.push_back(mapping[p]);
    
    return result;
}

void solve() {
    int N; cin>>N;
    init(N); build();
    ll res = 0;
    vector<int> inp(N);
    for (int i=0; i<N; i++) {
        cin>>inp[i];
    }
    vector<int> inp_comp = comp(inp);

    for (int x: inp_comp) {
        res += query(x+1, N);
        update(x, 1);
    }

    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}