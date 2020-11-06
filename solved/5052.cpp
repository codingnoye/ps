#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

struct Tri{
    map<int, Tri> mp;
    bool isTerm = false;
    Tri() {}
};

void solve() {
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        Tri tri = Tri();
        bool res = true;
        while (N--) {
            string tmp; cin>>tmp;
            Tri* now = &tri;
            for (int i=0; i<tmp.length(); i++) {
                int num = tmp.at(i)-'0';
                auto found = now->mp.find(num);
                if (found == now->mp.end()) {
                    now->mp[num] = Tri();
                    now = &(now->mp[num]);
                } else {
                    if (found->second.isTerm) {
                        res = false;
                        break;
                    }
                    now = &(found->second);
                }
            }
            if (now->mp.size() > 0) res = false;
            now->isTerm = true;
        }
        cout<<(res?"YES":"NO")<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}