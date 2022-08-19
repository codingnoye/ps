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
	gph[e].push_back({s, x, (int)gph[s].size()-1});
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

vector<bool> visited(510);
vector<int> team(510);
void dfs(int i) {
    if (visited[i]) return;
    visited[i] = true;
    if (team[i] == 0)
        team[i] = 1;

    for (auto& [pos, cap, rev]: gph[i]) {
        if (cap == 0) continue;
        dfs(pos);
    }
}

int main() {
    fastio;
    
    int N; cin>>N;
    // 노드: 1 ~ N
    // src = 0, sink = N+1
    int src = 0, sink = N+1;
    for (int i=1; i<=N; i++) {
        int x; cin>>x;
        if (x == 1) add_edge(src, i, 10000000);
        else if (x == 2) add_edge(i, sink, 10000000);

        team[i] = x;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int x; cin>>x;
            if (i==j) continue;
            if (j>i) continue;

            // if (team[i] != team[j])
            add_edge(i, j, x);
        }
    }
    ll mf = match(src, sink);
    dfs(src);
    cout<<mf<<endl;
    for (int i=1; i<=N; i++) {
        if (team[i] == 1) cout<<i<<' ';
    }
    cout<<endl;
    for (int i=1; i<=N; i++) {
        if (team[i] != 1) cout<<i<<' ';
    }
    cout<<endl;
}