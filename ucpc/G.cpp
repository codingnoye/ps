#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

bool used[5000001];
vector<int> useds;
bool cantuse[5000001];
int res[60001];
int reslen = 0;
const int INF = 987654321;
void solve() {
    int K, N; cin>>K>>N;
    int totalmax = 0;
    for(int i = 3; reslen<N*K; i++) {
        bool ac = false;
        int mn = INF;
        int pair;

        if (cantuse[i]) continue;
        for (int j=1; j<=i/2; j++) {
            int k = i-j;
            if (j==k) break;
            // cout<<"used["<<j<<"]: "<<used[j]<<endl;
            // cout<<"used["<<k<<"]: "<<used[k]<<endl;
            if (used[j] && used[k]) {
                ac = false;
                break;
            }
            // cout<<j<<' '<<k<<endl;
            int nowmin = min(j, k);
            int nowpair = max(j, k);
            if (!used[nowmin] && mn > nowmin && totalmax <= nowmin) {
                mn = nowmin;
                pair = nowpair;
                ac = true;
            } else if (!used[nowpair] && mn > nowpair && totalmax <= nowpair) {
                mn = nowpair;
                pair = nowmin;
                ac = true;
            }
        }

        if (ac && mn != INF) {
            // cout<<"pushed "<<(mn+pair)<<endl;
            int now = mn+pair;
            used[mn] = true;
            for (int i=0; i<reslen; i++) {
                cantuse[mn + res[i]] = true;
            }
            res[reslen++] = mn;
            totalmax = max(totalmax, mn);

            if (!used[pair] && totalmax <= pair) {
                used[pair] = true;
                for (int i=0; i<reslen; i++) {
                    cantuse[pair + res[i]] = true;
                }
                res[reslen++] = pair;
                totalmax = max(totalmax, pair);
            }
        }
    }
    for (int i=0; i<K; i++) {
        for (int j=0; j<N; j++) {
            cout<<res[i*N+j]<<" ";
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