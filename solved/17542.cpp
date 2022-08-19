#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int X, Y; cin>>X>>Y;

    vector<int> xs(X);
    vector<int> ys(Y);

    for (int i=0; i<X; i++) cin>>xs[i];
    for (int i=0; i<Y; i++) cin>>ys[i];

    sort(all(xs));
    sort(all(ys));

    for (int v: xs) {
        auto lb = lower_bound(ys.begin(), ys.end(), v);
        if (lb == ys.end()) {
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    for (int v: ys) {
        auto lb = lower_bound(xs.begin(), xs.end(), v);
        if (lb == xs.end()) {
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    cout<<"possible"<<endl;
}