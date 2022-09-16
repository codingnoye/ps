#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

// [a, b] all included edges
int get_dist(vector<int>& presum, int a, int b) {
    if (a > b) swap(a, b);
    return min(
        presum[b] - presum[a],
        presum[presum.size()-1] - (presum[b] - presum[a])
    );
}

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> presum(N+1);
    presum[0] = 0;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        presum[i+1] = presum[i] + x;
    }

    int res = 0;
    int j=1;
    for (int i=0; i<N; i++) {
        while (get_dist(presum, i, j) < get_dist(presum, i, j+1)) {
            j++;
        }
        res = max(get_dist(presum, i, j), res);
    }
    cout<<res<<endl;
}