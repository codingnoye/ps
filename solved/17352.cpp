#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
const int MAX = 300001;
int parent[MAX];
int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
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
    int N; cin>>N;
    for (int i=0; i<=N; i++) {
        parent[i] = i;
    }
    for (int i=0; i<N-2; i++) {
        int a, b; cin>>a>>b;
        uf_union(a, b);
    }
    int last = uf_find(1);
    for (int i=2; i<=N; i++) {
        int now = uf_find(i);
        if (now != last) {
            cout<<last<<' '<<now<<endl;
            break;
        }
    }
}