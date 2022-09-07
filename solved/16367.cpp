#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

struct SCC{
	vector<vector<int>> gph;
	 
	void init(int n){
		gph.clear();
		gph.resize(n);
	}
 
	void add_edge(int s, int e){
		gph[s].push_back(e);
	}
 
	vector<int> val, comp, z, cont;
	int Time, ncomps;
	template<class G, class F> int dfs(int j, G& g, F f) {
		int low = val[j] = ++Time, x; z.push_back(j);
		for(auto e : g[j]) if (comp[e] < 0)
			low = min(low, val[e] ?: dfs(e,g,f));
 
		if (low == val[j]) {
			do {
				x = z.back(); z.pop_back();
				comp[x] = ncomps;
				cont.push_back(x);
			} while (x != j);
			f(cont); cont.clear();
			ncomps++;
		}
		return val[j] = low;
	}
	template<class G, class F> void scc(G& g, F f) {
		int n = sz(g);
		val.assign(n, 0); comp.assign(n, -1);
		Time = ncomps = 0;
		for(int i=0; i<n; i++) if (comp[i] < 0) dfs(i, g, f);
	}
 
	int piv;
	void get_scc(int n){
		scc(gph, [&](vector<int> &v){});
		for(int i=0; i<n; i++){
			comp[i] = ncomps - comp[i];
		}
		piv = ncomps; 
	}
} scc;

struct SAT{
	SCC scc;
	int n;
	void init(int _n){ scc.init(2 * _n); n = _n; }
	int NOT(int x){ return x >= n ? (x - n) : (x + n); }
	void add_edge(int x, int y){
		if((x >> 31) & 1) x = (~x) + n;
		if((y >> 31) & 1) y = (~y) + n;
		scc.add_edge(x, y), scc.add_edge(NOT(y), NOT(x));
	}
	bool satisfy(vector<int>& res){
		scc.get_scc(2*n);
        res.clear();
        res.resize(n);
		for (int i=0; i<n; i++){
			if (scc.comp[i] == scc.comp[NOT(i)]) return 0;
			if (scc.comp[i] < scc.comp[NOT(i)]) res[i] = 0;
			else res[i] = 1;
		}
		return 1;
	}
} sat;

int main() {
    fastio;
    
    int K, N; cin>>K>>N;

    sat.init(K);

    for (int i=0; i<N; i++) {
        int a, b, c; char ga, gb, gc; cin>>a>>ga>>b>>gb>>c>>gc; a--; b--; c--;
        if (ga == 'B') a = ~a;
        if (gb == 'B') b = ~b;
        if (gc == 'B') c = ~c;

        sat.add_edge(~a, b); sat.add_edge(~a, c);
        sat.add_edge(~b, a); sat.add_edge(~b, c);
        sat.add_edge(~c, b); sat.add_edge(~c, a);
    }

    vector<int> res;
    if (sat.satisfy(res)) {
        for (int n: res) {
            if (n==0) cout<<'B';
            else cout<<'R';
        }
    } else {
        cout<<"-1"<<endl;
    }
}