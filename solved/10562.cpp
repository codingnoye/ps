#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <random>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;
typedef vector<int> vec;

const int mod = 1000000009;
using lint = long long;
lint ipow(lint x, lint p){
    lint ret = 1, piv = x;
    while(p){
        if(p & 1) ret = ret * piv % mod;
        piv = piv * piv % mod;
        p >>= 1;
    }
    return ret;
}
vec berlekamp_massey(vec x){
    vec ls, cur;
    int lf, ld;
    for(int i=0; i<x.size(); i++){
        lint t = 0;
        for(int j=0; j<cur.size(); j++){
            t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
        }
        if((t - x[i]) % mod == 0) continue;
        if(cur.empty()){
            cur.resize(i+1);
            lf = i;
            ld = (t - x[i]) % mod;
            continue;
        }
        lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
        vec c(i-lf-1);
        c.push_back(k);
        for(auto &j : ls) c.push_back(-j * k % mod);
        if(c.size() < cur.size()) c.resize(cur.size());
        for(int j=0; j<cur.size(); j++){
            c[j] = (c[j] + cur[j]) % mod;
        }
        if(i-lf+(int)ls.size()>=(int)cur.size()){
            tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
        }
        cur = c;
    }
    for(auto &i : cur) i = (i % mod + mod) % mod;
    return cur;
}
int get_nth(vec rec, vec dp, lint n){
    int m = rec.size();
    vec s(m), t(m);
    s[0] = 1;
    if(m != 1) t[1] = 1;
    else t[0] = rec[0];
    auto mul = [&rec](vec v, vec w){
        int m = v.size();
        vec t(2 * m);
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                t[j+k] += 1ll * v[j] * w[k] % mod;
                if(t[j+k] >= mod) t[j+k] -= mod;
            }
        }
        for(int j=2*m-1; j>=m; j--){
            for(int k=1; k<=m; k++){
                t[j-k] += 1ll * t[j] * rec[k-1] % mod;
                if(t[j-k] >= mod) t[j-k] -= mod;
            }
        }
        t.resize(m);
        return t;
    };
    while(n){
        if(n & 1) s = mul(s, t);
        t = mul(t, t);
        n >>= 1;
    }
    lint ret = 0;
    for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
    return ret % mod;
}
int guess_nth_term(vec x, lint n){
    if(n < x.size()) return x[n];
    vec v = berlekamp_massey(x);
    if(v.empty()) return 0;
    return get_nth(v, x, n);
}

/*
0 1

0 2
1 3

0 3
1 4
2 5

0 4
1 5
2 6
3 7
*/

vec seed[5];
const int seed_size = 512;
ull dp[1<<8][seed_size];

bool valid_state(int H, int left_col, int mid_col, int right_col) {
    int bp = 1;
    for (int y=0; y<H; y++, bp<<=1) {
        int v = bp & right_col;
        if (v==0) continue;
        if (y-2 >= 0 && (mid_col & (1<<(y-2)))) return false;
        if (y-1 >= 0 && (left_col & (1<<(y-1)))) return false;
        if (y+2 < H && (mid_col & (1<<(y+2)))) return false;
        if (y+1 < H && (left_col & (1<<(y+1)))) return false;
    }
    return true;
}

void make_seed() {
    for (int H=1; H<5; H++) {
        int BF = 1<<(H*2);
        int BF_COL = 1<<H;
        int LEFT_MASK = (1<<H)-1;
        for (int bf=0; bf<BF; bf++) dp[bf][0] = 0;
        for (int bf=0; bf<BF_COL; bf++) dp[bf<<H][0] = 1;
        for (int x=1; x<seed_size; x++) {
            int res = 0;
            for (int bf=0; bf<BF; bf++) {
                res += dp[bf][x-1];
                res %= mod;
            }
            seed[H].push_back(res);

            for (int bf=0; bf<BF; bf++) dp[bf][x] = 0;
            for (int bf=0; bf<BF; bf++) {
                int left_col = bf & LEFT_MASK;
                int mid_col = bf>>H;
                for (int right_col=0; right_col<BF_COL; right_col++) {
                    if (valid_state(H, left_col, mid_col, right_col)) {
                        int bf2 = mid_col + (right_col<<H);
                        dp[bf2][x] += dp[bf][x-1];
                        dp[bf2][x] %= mod;
                    }
                }
            }
        }
    }
}

void solve() {
    make_seed();
    int T; cin>>T;
    while (T--) {
        int H, W; cin>>H>>W;
        cout<<guess_nth_term(seed[H], W-1)<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}