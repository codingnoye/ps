#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int arr[200002];
vector<int> inps;
void solve() {
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        int res = 0;
        for (int i=0; i<200002; i++) {
            arr[i] = 0;
        }
        inps.clear();
        for (int i=0; i<N; i++) {
            int x; cin>>x;
            inps.push_back(x);
        }
        for (auto it=inps.rbegin(); it!=inps.rend(); it++) {
            int x = *it;
            res++;
            if (arr[x+1] == 0) arr[x+1] = 1;
            else if (arr[x] == 0) arr[x] = 1;
            else res--;
        }
        cout<<res<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}