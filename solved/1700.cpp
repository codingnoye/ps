#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, K; cin>>N>>K;

    vector<int> multitap;
    vector<deque<int>> usetimes(K+1);
    vector<int> inputs(K);

    for (int i=0; i<K; i++) {
        int x; cin>>x;
        inputs[i] = x;
        usetimes[x].push_back(i);
    }
    for (int i=0; i<=K; i++) {
        usetimes[i].push_back(987654321);
    }
    int ans = 0;
    for (int i=0; i<K; i++) {
        int x = inputs[i];
        if (multitap.size() < N) {
            bool found = false;
            for (int j=0; j<multitap.size(); j++) {
                if (multitap[j] == x) {
                    found = true;
                    break;
                }
            }
            usetimes[x].pop_front();
            if (found) continue;
            multitap.push_back(x);
        } else {
            int maxv = 0;
            int maxi = -1;
            int maxvv = 0;
            bool found = false;
            for (int j=0; j<multitap.size(); j++) {
                int v = multitap[j];
                if (v == x) {
                    found = true;
                    break;
                }
                if (maxv < usetimes[v].front()) {
                    maxv = usetimes[v].front();
                    maxvv = v;
                    maxi = j;
                }
            }
            usetimes[x].pop_front();
            if (!found) {
                // cout<<multitap[maxi]<<" to "<<x<<endl;
                multitap[maxi] = x;
                // for (int n: multitap) cout<<n<<' ';
                // cout<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}