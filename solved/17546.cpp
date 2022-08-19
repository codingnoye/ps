#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N, M; cin>>N>>M;

    vector<int> U, D;

    for (int i=0; i<M; i++) {
        int u, v; cin>>u>>v;
        if (u < v) U.push_back(i+1);
        else D.push_back(i+1);
    }
    if (U.size() > D.size()) swap(U, D);
    cout<<U.size()<<endl;
    for (int v: U) cout<<v<<endl;
}