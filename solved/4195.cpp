#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[200001];
int people[200001];
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
    people[max(pa, pb)] = people[pa] + people[pb];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while (T--){
        int N; cin>>N;
        for (int i=0; i<200001; i++) {
            parent[i] = i;
            people[i] = 1;
        }
        int id = 0;
        map<string, int> idmap;
        while (N--) {
            string a, b; cin>>a>>b;
            if (idmap.find(a) == idmap.end()) idmap[a] = id++;
            if (idmap.find(b) == idmap.end()) idmap[b] = id++;
            uf_union(idmap[a], idmap[b]);
            cout<<people[uf_find(idmap[a])]<<endl;
        }
    }
}