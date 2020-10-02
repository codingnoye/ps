#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

void solve() {
    int N, S; cin>>N>>S;
    int nums[20] = {0};
    for (int i=0; i<N; i++) cin>>nums[i];
    int mask = 1;
    int end = 1<<N;
    int res = 0;
    while (mask<end) {
        int nowval = 0;
        for (int i=1, j=0; j<N; i<<=1, j++) {
            if (mask&i) nowval += nums[j];
        }
        if (nowval == S) res++;
        mask++;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}