#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'
typedef long long ll;

bool solve(string s1_origin, string s1, string s2, int c1, int c2, int N) {
    pair<int, char> keep[2];
    keep[0] = {c1, s1_origin[c1]};
    keep[1] = {c2, s1_origin[c2]};
    int nowkeep = 0;
    
    int i1 = 0, i2 = 0;
    int cnt1o = 0, cnt1x = 0, cnt2o = 0, cnt2x = 0;
    while (i1 < N-2 && i2 < N) {
        if (s1[i1] == s2[i2]) {
            i1++; i2++;
        } else {
            if (nowkeep <= 1 && s2[i2] == keep[nowkeep].second) {
                i2++; nowkeep++;
            } else {
                return false;
            }
        }
    }
    while (nowkeep<2) {
        if (keep[nowkeep].second == s2[i2]) {
            nowkeep++; i2++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int N; cin>>N;
    string s1_origin, s2; cin>>s1_origin>>s2;
    int c1, c2; cin>>c1>>c2;
    string s1 = s1_origin.substr(0, c1) + s1_origin.substr(c1+1, c2 - (c1+1)) + s1_origin.substr(c2+1, s1_origin.size() - (c2+1));

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool b1 = solve(s1_origin, s1, s2, c1, c2, N);
    reverse(s1_origin.begin(), s1_origin.end());
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    bool b2 = solve(s1_origin, s1, s2, N-c2-1, N-c1-1, N);
    if (b1 || b2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}