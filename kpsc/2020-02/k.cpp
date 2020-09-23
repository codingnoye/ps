#include <iostream>
#include <vector>
using namespace std;

struct log {
    int val;
    int costa;
    int costb;
    log(int v=0, int a=0, int b=0) : val(v), costa(a), costb(b) {}
};
vector<log> dp[3][201];

int solve(int c, int i, int a, int b) {
    if (!dp[c][i].empty()) {
        for (auto it=dp[c][i].begin(); it!=dp[c][i].end(); it++) {
            if ((*it).costa<=a && (*it).costb<=b) {
                return (*it).val;
            }
        }
    }
    int res = 0;
    if (i==1) {
        if (c==0) {
            if (a>=1) res++;
            if (b>=2) res++;
        } else if (c==1) {
            if (b>=1) res++;
        } else res++;
    } else {
        if (c==0) {
            if (a>=2) res += solve(2, i-1, a-2, b);
            if (a>=1) {
                res += solve(0, i-1, a-1, b);
                if (b>=1) res += 2*solve(1, i-1, a-1, b-1);
            }
            if (b>=2) res += solve(0, i-1, a, b-2);
        } else if (c==1) {
            if (b>=1) res += solve(0, i-1, a, b-1);
            if (a>=1) res += solve(1, i-1, a-1, b);
        } else res += solve(0, i-1, a, b);
    }
    res%=1000;
    dp[c][i].push_back(log(res, a, b));
    return res;
}

int main() {
    int N, A, B; cin>>N>>A>>B;
    cout<<solve(0, N, A, B)<<endl;
}