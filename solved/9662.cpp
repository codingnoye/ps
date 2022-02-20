#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int NAIVE_RANGE = 100000;
const int FIND_START = 50009;
const int FIND_END = 100000;

int dp[NAIVE_RANGE];
void solve() {
    ll N; cin>>N;
    int K; cin>>K;
    vector<int> methods(K);
    for (int i=0; i<K; i++) {
        cin>>methods[i];
    }

    for (int i=1; i<NAIVE_RANGE; i++) {
        for (int m: methods) {
            if (i-m >= 0 && dp[i-m] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    
    ll S;
    for (int s=1; s<1000; s++) {
        bool allsame = true;
        for (int offset=0; offset<s; offset++) {
            if (!allsame) break;
            int val = dp[FIND_START+offset];
            for (int i=FIND_START+offset; i<FIND_END; i+=s) {
                if (val != dp[i]) {
                    allsame = false;
                    break;
                }
            }
        }
        if (allsame) {
            S = s;
            break;
        }
    }
    ll cnt_nocycle = 0;
    for (int i=1; i<FIND_START; i++) {
        cnt_nocycle += 1-dp[i];
    }
    ll cnt_cycle = 0;
    for (int i=FIND_START; i<FIND_START+S; i++) {
        cnt_cycle += 1-dp[i];
    }
    ll cnt;
    if (N < FIND_START) {
        cnt = 0;
        for (int i=1; i<=N; i++) {
            cnt += 1-dp[i];
        }
    } else {
        cnt = cnt_nocycle;
        cnt += (N-FIND_START)/S*cnt_cycle;
        for (int i=FIND_START;i<=(N-FIND_START)%S+FIND_START; i++) {
            cnt += 1-dp[i];
        }
    }
    //cout<<S<<endl;
    cout<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}