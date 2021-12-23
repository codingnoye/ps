// from koosaga
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXN = 8000; // 이거 바꿔야함
struct edg{ int pos, cap, rev, cost; };
vector<edg> gph[MAXN];
void clear(){
    for(int i=0; i<MAXN; i++) gph[i].clear();
}
// s에서 e로, 최대 x, 비용 c
void add_edge(int s, int e, int x, int c){
    gph[s].push_back({e, x, (int)gph[e].size(), c});
    gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
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

bool seat[82][82];

int ptoi(int i, int j) {
    return 2+i*81+j;
}

void solve() {

    const int src = 0;
    const int sink = 1;

    // 좌표에서 번호로 변환:
    // i * 80 + j
    int T; cin>>T;
    while (T--) {
        int N, M; cin>>N>>M;
        clear();
        for (int i=0; i<82; i++) {
            for (int j=0; j<82; j++) {
                seat[i][j] = 0;
            }
        }
        
        int total = 0;
        for (int i=0; i<N; i++) {
            string tmp; cin>>tmp;
            for (int j=0; j<M; j++) {
                seat[i][j] = tmp.at(j) == '.';
                if (seat[i][j]) total++;
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j+=2) {
                if (seat[i][j]) {
                    add_edge(src, ptoi(i, j), 1, 0);
                    if (i>0 && j>0 && seat[i-1][j-1]) add_edge(ptoi(i, j), ptoi(i-1, j-1), 1, 0);
                    if (j>0 && seat[i][j-1]) add_edge(ptoi(i, j), ptoi(i, j-1), 1, 0);
                    if (j>0 && i<N-1 && seat[i+1][j-1]) add_edge(ptoi(i, j), ptoi(i+1, j-1), 1, 0);
                    if (i>0 && j<M-1 && seat[i-1][j+1]) add_edge(ptoi(i, j), ptoi(i-1, j+1), 1, 0);
                    if (j<M-1 && seat[i][j+1]) add_edge(ptoi(i, j), ptoi(i, j+1), 1, 0);
                    if (j<M-1 && i<N-1 && seat[i+1][j+1]) add_edge(ptoi(i, j), ptoi(i+1, j+1), 1, 0);
                }
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=1; j<M; j+=2) {
                if (seat[i][j]) {
                    add_edge(ptoi(i, j), sink, 1, 0);
                }
            }
        }
        auto [mc, mf] = match(src, sink);
        cout<<total-mf<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}