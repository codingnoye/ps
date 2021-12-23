#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef vector<pair<int, int>> vec;
vec get_lis(vec& arr) {
    int n = arr.size();
    vec tmp = vec();
    vector<int> from = vector<int>();
    for (auto x: arr) {
        int loc = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
        if (loc == tmp.size()) {
            tmp.push_back(x);
        } else {
            tmp[loc] = x;
        }
        from.push_back(loc);
    }
    vec lis = vec(tmp.size());
    int target = tmp.size()-1;
    for (int i=n-1; i>=0; i--) {
        if (target == from[i]) {
            lis[target--] = arr[i];
        }
    }
    return lis;
}

void solve() {
    int N; cin>>N;
    vector<pair<int, int>> inp(500001);
    for (int i=0; i<N; i++) {
        int a, b; cin>>a>>b;
        inp[a] = {b, a};
    }
    vector<pair<int, int>> comp;
    for (int i=0; i<500001; i++) {
        if (inp[i].first != 0) comp.push_back(inp[i]);
    }
    auto lis = get_lis(comp);
    // cout<<"=="<<endl;
    // for (auto i: comp) cout<<i.first<<' '<<i.second<<endl;
    // cout<<"=="<<endl;
    cout<<comp.size()-lis.size()<<endl;
    // cout<<"=="<<endl;
    // for (auto i: lis) cout<<i.first<<' '<<i.second<<endl;
    // cout<<"=="<<endl;
    int i=0, j=0;
    while (i < comp.size()) {
        if (comp[i].second != lis[j].second) {
            cout<<comp[i++].second<<endl;    
        } else {
            i++;
            j++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}