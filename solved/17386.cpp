#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

struct Point{
    ll x;
    ll y;
    Point(ll x=0, ll y=0) : x(x), y(y){}    
};
bool operator< (Point A, Point B) {
    return pair{A.x, A.y} < pair{B.x, B.y};
}

// a, b, c 순서로 Counter clockwise라면 양수
// 절대값에 2를 나누면 면적
ll ccw(Point a, Point b, Point c, bool sign_only=false) {
    ll val = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
    if (sign_only && val!=0) return val/abs(val);
    return val;
}

// 선분 교차
bool is_intersect(Point A1, Point A2, Point B1, Point B2) {
    ll ccw1 = ccw(A1, A2, B1, true)*ccw(A1, A2, B2, true);
    ll ccw2 = ccw(B1, B2, A1, true)*ccw(B1, B2, A2, true);
    if (ccw1 == 0 && ccw2 == 0) {
        if (A2 < A1) swap(A1, A2);
        if (B2 < B1) swap(B1, B2);
        return A2 < B1 || B2 < A1;
    }
    return ccw1 <= 0 && ccw2 <= 0;
}

void solve() {
    ll a, b, c, d, e, f, g, h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if (is_intersect({a, b}, {c, d}, {e, f}, {g, h})) cout<<1<<endl;
    else cout<<0<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}