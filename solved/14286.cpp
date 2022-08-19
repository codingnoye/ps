#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 501; // 이거 바꿔야함
struct edg{ int pos, cap, rev, cost; };
vector<edg> gph[MAXN];
void clear(){
    for(int i=0; i<MAXN; i++) gph[i].clear();
}
// s에서 e로, 최대 x, 비용 c
void add_edge(int s, int e, int x, int c){
    gph[s].push_back({e, x, (int)gph[e].size(), c});
    gph[e].push_back({s, x, (int)gph[s].size()-1, c});
}
int dist[MAXN], pa[MAXN], pe[MAXN];
bool inque[MAXN];
const int dist_inf = 5000000;// 이거 바꿔야함
bool spfa(int src, int sink){
    fill(dist, dist+MAXN, dist_inf);
    fill(inque, inque+MAXN, 0);
    queue<int> que;
    dist[src] = 0;
    inque[src] = 1;
    que.push(src);
    bool ok = 0;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        if(x == sink) ok = 1;
        inque[x] = 0;
        for(int i=0; i<gph[x].size(); i++){
            edg e = gph[x][i];
            if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
                dist[e.pos] = dist[x] + e.cost;
                pa[e.pos] = x;
                pe[e.pos] = i;
                if(!inque[e.pos]){
                    inque[e.pos] = 1;
                    que.push(e.pos);
                }
            }
        }
    }
    return ok;
}
pair<int, int> match(int src, int sink){
    int mc = 0;
    int mf = 0;
    while(spfa(src, sink)){
        int cap = 1e9;
        for(int pos = sink; pos != src; pos = pa[pos]){
            cap = min(cap, gph[pa[pos]][pe[pos]].cap);
        }
        mc += dist[sink] * cap;
        mf += cap;
        for(int pos = sink; pos != src; pos = pa[pos]){
            int rev = gph[pa[pos]][pe[pos]].rev;
            gph[pa[pos]][pe[pos]].cap -= cap;
            gph[pos][rev].cap += cap;
        }
    }
    return {mc, mf};
}

int main() {
    fastio;
    
    int N, M; cin>>N>>M;
    // 노드: 0 ~ N-1
    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        add_edge(a-1, b-1, c, 0);
    }
    int s, t; cin>>s>>t;
    auto [mc, mf] = match(s-1, t-1);
    cout<<mf<<endl;
}