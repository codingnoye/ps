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

bool need[101];
int N, M;
int K;
int res;

vector<ii> conds;
vector<ii> options;

void attempt(int k) {
    if (k == K) {
        int nowres = 0;
        for (ii cond: conds) {
            if ((!need[cond.first]) && (!need[cond.second])) {
                nowres++;
            }
        }
        res = max(res, nowres);
    } else {
        ii now = options[k];
        if (need[now.first]) {
            need[now.first] = false;
            attempt(k+1);
            need[now.first] = true;
        } 
        if (need[now.second]) {
            need[now.second] = false;
            attempt(k+1);
            need[now.second] = true;
        } 
        if (!(need[now.first]) && !(need[now.second])) {
            attempt(k+1);
        }
    }
}
void solve() {
    cin>>N>>M;
    for (int _=0; _<M; _++) {
        int a, b; cin>>a>>b;
        need[a] = true;
        need[b] = true;
        conds.push_back({a, b});
    }
    cin>>K;
    for (int _=0; _<K; _++) {
        int c, d; cin>>c>>d;
        options.push_back({c, d});
    }
    attempt(0);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}