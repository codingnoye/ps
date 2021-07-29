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
int nodes[360000];
void init(int n) {
    N = n;
    H = 0;
    for (S=1; S<n; S<<=1) H++;
    for (int i=0; i<2*S; i++) nodes[i] = 1;
}
void build () {
    for (int i=S-1; i>=1; i--)  {
        nodes[i] = nodes[i*2] * nodes[i*2+1];
    }
}
void update(int x, int v) {
    int now = S+x;
    nodes[now] = (v>0?1:(v<0?-1:0));
    while (now>1) {
        now /= 2;
        nodes[now] = nodes[now*2] * nodes[now*2+1];
    }
}
int query(int s, int e, int now, int d) {
    int size = 1<<(H-d);
    int si = now * (1<<(H-d)) - S;
    int ei = si + size;
    //cout<<"query now "<<now<<" d "<<d<<" s "<<s<<" e "<<e<<" si "<<si<<" ei "<<ei<<endl;
    if (s<=si && ei<=e) {
        return nodes[now]; 
    } else if (ei <= s || e <= si) {
        return 1; // 완전히 범위 밖인경우
    } else {
        int left = query(s, e, now*2, d+1);
        int right = query(s, e, now*2+1, d+1);
        return left*right;
    }
}

void solve() {
    int n, k; 
    while (cin>>n>>k) {
        init(n);
        for (int i=0; i<n; i++) {
            int x; cin>>x;
            nodes[S+i] = (x>0?1:(x<0?-1:0));
        }
        build();
        //for (int i=1; i<2*S; i++) cout<<nodes[i]<<" "; cout<<endl;
        while (k--) {
            char a; int b, c; cin>>a>>b>>c;
            if (a == 'C') {
                update(b-1, c);
                //for (int i=1; i<2*S; i++) cout<<nodes[i]<<" "; cout<<endl;
            } else {
                int res = query(b-1, c, 1, 0);
                cout<<(res>0?'+':(res<0?'-':'0'));
            }
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}