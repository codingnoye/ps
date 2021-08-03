#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

const int INF = 1000000001;
int N;
int S;
int H;
ii nodes[360000];
void init(int n) {
    N = n;
    H = 0;
    for (S=1; S<n; S<<=1) H++;
    for (int i=0; i<2*S; i++) {
        nodes[i].first = 0;
        nodes[i].second = INF;
    }
}
void build () {
    for (int i=S-1; i>=1; i--)  {
        if (nodes[i*2].second < nodes[i*2+1].second || (nodes[i*2].second == nodes[i*2+1].second && nodes[i*2].first < nodes[i*2+1].first)) {
            nodes[i].first = nodes[i*2].first;
            nodes[i].second = nodes[i*2].second;
        } else {
            nodes[i].first = nodes[i*2+1].first;
            nodes[i].second = nodes[i*2+1].second;
        }
    }
}
void update(int x, int v) {
    int now = S+x;
    nodes[now].second = v;
    while (now>1) {
        now /= 2;
        if (nodes[now*2].second < nodes[now*2+1].second || (nodes[now*2].second == nodes[now*2+1].second && nodes[now*2].first < nodes[now*2+1].first)) {
            nodes[now].first = nodes[now*2].first;
            nodes[now].second = nodes[now*2].second;
        } else {
            nodes[now].first = nodes[now*2+1].first;
            nodes[now].second = nodes[now*2+1].second;
        }
    }
}
ii query(int s, int e, int now, int d) {
    int size = 1<<(H-d);
    int si = now * (1<<(H-d)) - S;
    int ei = si + size;
    if (s<=si && ei<=e) {
        return nodes[now]; 
    } else if (ei <= s || e <= si) {
        return ii(INF, INF);
    } else {
        ii left = query(s, e, now*2, d+1);
        ii right = query(s, e, now*2+1, d+1);
        if (left.second < right.second || (left.second == right.second && left.first < right.first))  
            return left;
        else
            return right;
    }
}

void solve() {
    int n, k; cin>>n;
    init(n);
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        nodes[S+i].first = i;
        nodes[S+i].second = x;
    }
    build();
    cin>>k;
    while (k--) {
        int a, b, c; cin>>a>>b>>c;
        if (a == 1) {
            update(b-1, c);
        } else {
            ii res = query(b-1, c, 1, 0);
            cout<<(res.first+1)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}