#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'

typedef long long int ll;
typedef pair<ll, ll> ii;

ll ccw(ii& a, ii& b, ii& c) {
    return 1LL*(b.first-a.first)*(c.second-a.second) - 1LL*(b.second-a.second)*(c.first-a.first);
}
ii axis;
ll ccw2(ii& a, ii& b, ii& c, ii& d) {
    ii e = {d.first - c.first + b.first, d.second - c.second + b.second};
    return ccw(a, b, e);
}

bool comp(ii& a, ii& b) {
    return (a.second<b.second || (a.second==b.second && a.first<b.first));
}
ll dist(ii& a, ii& b) {
    return ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool compAngle(ii& a, ii& b) {
    ll cw = ccw(axis, a, b);
    return cw > 0 || (cw==0 && a.second < b.second);
}
void solve() {
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        vector<ii> points;
        for (int i=0; i<N; i++) {
            int x,y; cin>>x>>y;
            points.push_back({x, y});
        }
        sort(points.begin(), points.end(), comp);
        axis = points[0];
        sort(points.begin()+1, points.end(), compAngle);
        stack<ii> st;
        st.push(points[0]);
        st.push(points[1]);
        int i = 2;
        while (i<N) {
            while (st.size()>=2) {
                ii a = st.top(); st.pop();
                ii b = st.top();
                ii now = points[i];
                if (ccw(b, a, now) > 0) {
                    st.push(a);
                    break;
                }
            }
            st.push(points[i]);
            i++;
        }
        vector<ii> convex;
        convex.resize(st.size());
        for (int i=st.size()-1; i>=0; i--) {
            convex[i] = st.top();
            st.pop();
        }
        int c = 1;
        ll maxlen = 0;
        ii p1, p2;
        int size = convex.size();
        for (int a=0; a<=size; a++) {
            ii pa = convex[a%size];
            while (true) {
                ii pc = convex[c];
                ll len = dist(pa, pc);
                
                if (maxlen<len) {
                    maxlen = len;
                    p1 = pa;
                    p2 = pc;
                }
                ll ccw = ccw2(pa, convex[(a+1)%size], pc, convex[(c+1)%size]);
                if (ccw > 0) {
                    c++;
                    c %= size;
                } else {
                    break;
                }
            }
        }
        cout<<p1.first<<' '<<p1.second<<' '<<p2.first<<' '<<p2.second<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}