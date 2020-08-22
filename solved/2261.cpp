#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
    point(int x=0, int y=0) : x(x), y(y) {}
    bool operator< (const point& p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};
bool compX(const point& a, const point& b) {
    return a.x < b.x;
}
int dis(point a, point b) {
    int x = (a.x-b.x);
    int y = (a.y-b.y);
    return x*x+y*y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    point arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr, arr+n, compX);
    int D = dis(arr[0], arr[1]);
    int roiStart = 0;
    set<point> roi = {arr[0], arr[1]};
    for (int i=2; i<n; i++) {
        point p = arr[i];
        while (roiStart<i) {
            point q = arr[roiStart];
            int XD = p.x-q.x;
            if (XD*XD>D) {
                roi.erase(q);
                roiStart+=1;
            }
            else break;
        }
        int SD = (int)sqrt((double)D)+1;
        auto lowerY = roi.lower_bound(point(-100000, p.y-SD));
        auto upperY = roi.upper_bound(point(100000, p.y+SD));
        for (auto it=lowerY; it!=upperY; it++) {
            const int DD = dis(p, *it);
            if (DD < D) {
                D = DD;
            }
        }
        roi.insert(p);
    }
    cout<<D;
}