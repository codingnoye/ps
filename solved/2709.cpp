#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<ll> res = {0, 
    1, 9, 89, 89, 589, 
    3089, 3089, 3089, 315589, 315589,
    8128089, 164378089, 945628089, 1922190589, 11687815589LL,
    109344065589LL, 231414378089LL, 1452117503089LL, 4503875315589LL, 65539031565589LL
};
void solve() {
    int T; cin>>T;
    while (T--) {
        int x; cin>>x;
        cout<<res[x]<<endl;        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}