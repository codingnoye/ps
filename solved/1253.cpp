#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> A(N);
    vector<bool> counted(N);
    map<int, set<int>> where;
    for (int i=0; i<N; i++) cin>>A[i];
    for (int i=0; i<N; i++) {
        int a = A[i];
        if (where.find(a) == where.end()) where[a] = {i};
        else where[a].insert(i);
    }
    int ans = 0;
    for (int i=0; i<N; i++) {
        int a = A[i];
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            int b = A[j];
            if (where.find(a+b) == where.end()) continue;
            vector<int> counted_now;
            for (int k: where[a+b]) {
                if (!counted[k] && k!=i && k!=j) {
                    counted[k] = true;
                    counted_now.push_back(k);
                    ans++;
                }
            }
            for (int k: counted_now) where[a+b].erase(k);
        }
    }
    cout<<ans<<endl;
}