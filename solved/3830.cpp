#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int, int> ii;
int parent[1000001];
int offset[1000001];
ii uf_find(int x) {
    if (parent[x] == x) return {x, 0};
    ii par = uf_find(parent[x]);
    parent[x] = par.first;
    offset[x] = offset[x] + par.second;
    //cout<<"uf("<<x<<") is "<<parent[x]<<", "<<offset[x]<<endl;
    return {parent[x], offset[x]};
}
void uf_union(int a, int b, int df) {
    ii pa, pb;
    pa = uf_find(a);
    pb = uf_find(b);
    if (pa == pb) return;
    parent[pb.first] = pa.first;
    offset[pb.first] = pa.second - pb.second + df;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int N, M; cin>>N>>M;
        if (!(N||M)) break;
        for (int i=1; i<=N; i++) {
            parent[i] = i;
            offset[i] = 0;
        }
        for (int i=0; i<M; i++) {
            string a; int b, c; cin>>a>>b>>c;
            if (a=="!") {
                int d; cin>>d;
                uf_union(b, c, d);
            } else {
                ii pa, pb;
                pa = uf_find(b);
                pb = uf_find(c);
                if (pa.first != pb.first) {
                    cout<<"UNKNOWN"<<endl;
                } else {
                    //cout<<"pb s "<<pb.second<<" pa s "<<pa.second<<endl;
                    //cout<<"pb f "<<pb.first<<" pa f "<<pa.first<<endl;
                    cout<<(pb.second-pa.second)<<endl;
                }
            }
        } 
    }
}