#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int gcd(int p, int q) {
    return q == 0 ? p : gcd(q, p % q);
}

void solve() {
    int C; cin>>C;
    while (C--) {
        int n; cin>>n;
        vector<int> recipe(n);
        for (int i = 0; i < n; i++) cin>>recipe[i];
        vector<int> fuck(n);
        for (int i = 0; i < n; i++) cin>>fuck[i];

        int g = recipe[0];
        for (int i = 1; i < n; i++) g = gcd(g, recipe[i]);
        vector<int> dived(n);
        for (int i = 0; i < n; i++) {
            dived[i] = recipe[i] / g;
        }
        int mul = 1;
        while (true) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (!(dived[i]*mul >= fuck[i] && dived[i]*mul >= recipe[i])) {
                    flag = false;
                    break;
                }
            }
            if (flag) break;
            mul++;
        }
        for (int i = 0; i < n; i++) {
            cout<<(dived[i]*mul - fuck[i])<<' ';
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}