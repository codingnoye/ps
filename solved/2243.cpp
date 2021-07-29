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

int N;
int S;
int H;
int nodes[3000000];
void init(int n) {
    N = n;
    H = 0;
    for (S=1; S<n; S<<=1) H++;
    for (int i=0; i<2*S; i++) nodes[i] = 0;
}
void build () {
    for (int i=S-1; i>=1; i--)  {
        nodes[i] = nodes[i*2] + nodes[i*2+1];
    }
}
void update(int x, int v) {
    int now = S+x;
    nodes[now] = v;
    while (now>1) {
        now /= 2;
        nodes[now] = nodes[now*2] + nodes[now*2+1];
    }
}
int query(int s, int e, int now, int d) {
    int size = 1<<(H-d);
    int si = now * (1<<(H-d)) - S;
    int ei = si + size;
    if (s<=si && ei<=e) {
        return nodes[now]; 
    } else if (ei <= s || e <= si) {
        return 0;
    } else {
        int left = query(s, e, now*2, d+1);
        int right = query(s, e, now*2+1, d+1);
        return left+right;
    }
}
int lowerbound(int s, int e, int x) {
    int m;
    while (s < e) {
        m = (s+e)/2;
        if (query(0, m+1, 1, 0) < x) s = m + 1;
        else e = m;
    }
    return e;
}

void solve() {
    int n;
    cin>>n;
    init(1000100);
    build();
    //for (int i=1; i<2*S; i++) cout<<nodes[i]<<" "; cout<<endl;
    while (n--) {
        int a, b, c;
        cin>>a;
        if (a == 1) {
            cin>>b;
            int res = lowerbound(0, S, b);
            cout<<res<<endl;
            update(res, nodes[S+res]-1);
        } else {
            cin>>b>>c;
            update(b, nodes[S+b]+c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}