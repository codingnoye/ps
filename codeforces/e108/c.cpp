#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int st_univs[200001];
int st_skills[200001];
map<int, vector<ull>> univs;
vector<vector<ull>> uu;
vector<ull> u2;
void solve() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        for (int i=0; i<N; i++) scanf("%d", st_univs+i);
        for (int i=0; i<N; i++) scanf("%d", st_skills+i);
        univs.clear();
        for (int i=0; i<N; i++) {
            univs[st_univs[i]].push_back(st_skills[i]);
        }
        uu.clear();
        for (auto iu: univs) {
            auto u = iu.second;
            sort(u.rbegin(), u.rend());
            u2.clear();
            u2.resize(u.size()+1);
            u2[0] = 0;
            for (int i=0; i<u.size(); i++) {
                u2[i+1] = u2[i] + u[i];
            }
            uu.push_back(u2);
        }
        for (int k=1; k<=N; k++) {
            ull res = 0;
            for (auto u: uu) {
                res += u[((u.size()-1)/k)*k];
            }
            printf("%lld ", res);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}