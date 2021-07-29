#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl '\n'

typedef long long int ll;
typedef pair<ll, ll> ii;

ll ccw(ii& a, ii& b, ii& c) {
    return 1LL*(b.first-a.first)*(c.second-a.second) - 1LL*(b.second-a.second)*(c.first-a.first);
}
ii axis;
ll ccw2(ii a, ii b, ii c, ii d) {
    d.first = d.first - c.first + b.first;
    d.second = d.second - c.second + b.second;
    return ccw(a, b, d);
}

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
    stack<ii> tmp;
    while (st.size()) {
        tmp.push(st.top()); st.pop();
    }  
    vector<ii> convex;
    while (tmp.size()) {
        convex.push_back(tmp.top()); tmp.pop();
    }
    int a = 0;
    int c = 1;
    ll maxlen = 0;
    int size = convex.size();
    while (true) {
        ll len = dist(convex[a], convex[c]);
        //cout<<convex[a].first<<" "<<convex[a].second<<" "<<convex[c].first<<" "<<convex[c].second<<" "<<sqrt(len)<<endl;
        maxlen = max(len, maxlen);
        int ccw = ccw2(convex[a], convex[(a+1)%size], convex[c], convex[(c+1)%size]);
        if (ccw > 0) {
            c = c+1;
            c = c%size;
        } else {
            a = a+1;
            a = a%size;
            if (a%size==0) break;
        }
    }
    cout<<fixed;
    cout.precision(7);
    cout<<((double)sqrt(maxlen))<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}