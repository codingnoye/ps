#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 505;
struct edg{ int pos, cap, rev; };
vector<edg> gph[MAXN];
void clear(){ for(int i=0; i<MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, int x){
	gph[s].push_back({e, x, (int)gph[e].size()});
	gph[e].push_back({s, 0, (int)gph[s].size()-1});
}
int dis[MAXN], pnt[MAXN];
bool bfs(int src, int sink){
	memset(dis, 0, sizeof(dis));
	memset(pnt, 0, sizeof(pnt));
	queue<int> que;
	que.push(src);
	dis[src] = 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &e : gph[x]){
			if(e.cap > 0 && !dis[e.pos]){
				dis[e.pos] = dis[x] + 1;
				que.push(e.pos);
			}
		}
	}
	return dis[sink] > 0;
}
int dfs(int x, int sink, int f){
	if(x == sink) return f;
	for(; pnt[x] < gph[x].size(); pnt[x]++){
		edg e = gph[x][pnt[x]];
		if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
			int w = dfs(e.pos, sink, min(f, e.cap));
			if(w){
				gph[x][pnt[x]].cap -= w;
				gph[e.pos][e.rev].cap += w;
				return w;
			}
		}
	}
	return 0;
}
ll match(int src, int sink){
	ll ret = 0;
	while(bfs(src, sink)){
		int r;
		while((r = dfs(src, sink, 2e9))) ret += r;
	}
	return ret;
}

bool visited[550];
void visit(int i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto& [pos, cap, rev]: gph[i]) {
        if (cap == 0) continue;
        visit(pos);
    }
}

int main() {
    fastio;
    
    int N, M; cin>>N>>M;

    int S, T; cin>>S>>T;

    // [1, N] IN
    // [N+1, 2*N] OUT

    for (int i=1; i<=N; i++) {
        ll c; cin>>c;
        add_edge(i, i+N, c);
    }
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        add_edge(a+N, b, 100000000);
        add_edge(b+N, a, 100000000);
    }
    ll res = match(S, T+N);

    visit(S);
    for (int i=1; i<=N; i++) {
        if (visited[i] && !visited[i+N]) {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}