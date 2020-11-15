#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define endl '\n'
int parent[100001];
vector<unordered_set<int>> child;
int nodeclass[100001];
int input_n;
int uf_find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = uf_find(parent[x]);
}
void uf_union(int a, int b) {
    int pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return;
    parent[max(pa, pb)] = min(pa, pb);
    for (auto it=child[max(pa, pb)].begin(); it!=child[max(pa, pb)].end(); it++) child[min(pa, pb)].insert(*it);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Q; cin>>input_n>>Q;
    child.resize(input_n+1);
    for (int i=1; i<=input_n; i++) {
        parent[i] = i;
        int x; cin>>x;
        nodeclass[i] = x;
        child[i].insert(i);
    }
    while (Q--) {
        int a, b, c; cin>>a>>b>>c;
        if (a==1) {
            uf_union(b, c);
        } else {
            auto s = child[uf_find(b)];
            int cnt = 0;
            for (auto x: s) {
                if (nodeclass[x] == c) cnt++;
            }
            cout<<cnt<<endl;
        }
    }
}