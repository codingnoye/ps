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

    vector<pair<ull, ull>> friends; 

    void solve() {
        ull n, money; cin>>n>>money;
        for (int i=0; i<n; i++) {
            ull a; int b; cin>>a>>b;
            friends.push_back({a, b});
        }
        sort(friends.begin(), friends.end());
        ull now = 0;
        for (auto f: friends) {
            ull v = f.first;
            ull m = f.second;
            if (now + money < v) {
                now = now + money;
                money = 0;
                break;
            } else {
                money -= v - now;
                now = v;
                money += m;
            }
        }
        if (money > 0) {
            now = now + money;
        }
        cout<<now<<endl;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve();
        return 0;
    }