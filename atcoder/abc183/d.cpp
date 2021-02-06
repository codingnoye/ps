#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ull, ull> puu;
typedef pair<ll, ll> pll;

struct act{
    int time;
    int water;
    int isStart;
    act(int t, int w, int i) : time(t), water(w), isStart(i) {};
};

bool cmp(const act &a, const act &b) {
    if (a.time < b.time) return true;
    else if (a.time == b.time) {
        return a.isStart < b.isStart;
    } else {
        return false;
    }
}

void solve() {
    int N, W; cin>>N>>W;
    vector<act> v;
    for (int i=0; i<N; i++) {
        int s, t, p; cin>>s>>t>>p;
        v.push_back(act{t, p, 0}); // 0 is end
        v.push_back(act{s, p, 1}); // 1 is start
    }
    sort(v.begin(), v.end(), cmp);
    int water = 0;
    for (auto it=v.begin(); it<v.end(); it++) {
        act now = *it;
        if (now.isStart==1) {
            water += now.water;
        } else {
            water -= now.water;
        }
        if (water > W) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}