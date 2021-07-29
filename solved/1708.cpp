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

bool comp(ii& a, ii& b) {
    return (a.second<b.second || (a.second==b.second && a.first<b.first));
}
ll dist(ii& a, ii& b) {
    return 1LL * ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool compAngle(ii& a, ii& b) {
    ll cw = ccw(axis, a, b);
    return cw > 0 || (cw==0 && dist(axis, a) < dist(axis, b));
}
void solve() {
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
    cout<<st.size()<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}