#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

bool sieve[100001];
vector<int> sosus;
void solve() {
    for (int i=2; i<100001; i++) {
        if (!sieve[i]) {
            sosus.push_back(i);
            for (int j=i*2; j<100001; j+=i) {
                sieve[j] = true;
            }
        }
    }

    int T; cin>>T;
    for (int tc=1; tc<=T; tc++) {
        int N; cin>>N;
        map<int, int> ans;
        for (int sosu: sosus) {
            while (N%sosu == 0) {
                if (ans.find(sosu) == ans.end()) {
                    ans[sosu] = 1;
                } else {
                    ans[sosu]++;
                }
                N /= sosu;
            }
        }
        for (auto it: ans) {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}