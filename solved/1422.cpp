#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
	fastio;

    vector<string> v;
    int mx = 0;

    int K, N; cin>>K>>N;
    ff(i, 0, K) {
        string x; cin>>x;
        v.push_back(x);
        mx = max(stoi(x), mx);
    }
    ff(i, K, N) {
        v.push_back(to_string(mx));
    }

	sort(v.begin(), v.end(), [&](string a, string b) {
		return a + b > b + a;
	});

	for (auto i : v) cout << i; cout << '\n';
}