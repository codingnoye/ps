#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[1000001];
int uf_find(int x) {
    if (parent[x] == x) return x;
    return uf_find(parent[x]);
}
void uf_union(int a, int b) {
    int pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return;
    parent[min(pa, pb)] = max(pa, pb);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin>>N>>M;
    for (int i=0; i<=N; i++) {
        parent[i] = i;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int x; cin>>x;
            if (x==1)
                uf_union(i, j);
        }
    }
    int x; cin>>x;
    int group = uf_find(x-1);
    for (int i=1; i<M; i++) {
        cin>>x;
        int now = uf_find(x-1);
        if (group != now) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}