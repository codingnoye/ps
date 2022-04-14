#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

struct node {
    ll label = 0;
    bool finished = false;
    vector<int> adj;
    ll group;
};
vector<node> nodes;

ll num_label;
ll num_group;
stack<int> st;

void clear() {
    num_label = 0;
    num_group = 0;
    while (!st.empty()) st.pop();
    nodes.clear();
}

// 각 노드마다 d가 0이라면 dfs 실행
ll dfs(int n_id) {
    node& n = nodes[n_id];
	n.label = ++num_label; // 노드마다 고유한 번호를 할당 
	st.push(n_id); // 스택에 자기 자신을 삽입 
	
	ll parent = n.label;
	for(int a_id: n.adj) {
        node& a = nodes[a_id];
		if(a.label == 0) parent = min(parent, dfs(a_id)); // 방문하지 않은 이웃 
		else if(!a.finished) parent = min(parent, a.label); // 처리중인 이웃 
	}
	
	if(parent == n.label) { // 부모노드가 자기 자신인 경우 
		while (true) {
			int t_id = st.top();
            node& t = nodes[t_id];
            t.group = num_group;
			st.pop();
			t.finished = true;
			if(t_id == n_id) break;
		}
        num_group++;
	}
	
	// 자신의 부모 값 반환
	return parent; 
}

void solve() {
    int T; cin>>T;
    while (T--) {
        num_label = 0;
        num_group = 0;
        while (!st.empty()) st.pop();
        nodes.clear();
        int V, E; cin>>V>>E;
        nodes.resize(V);
        vector<pair<int, int>> edges;
        for (int i=0; i<E; i++) {
            int a, b; cin>>a>>b;
            edges.push_back({a-1, b-1});
            nodes[a-1].adj.push_back(b-1);
        }
        for (int i=0; i<V; i++) {
            if (nodes[i].label == 0) dfs(i);
        }
        vector<int> in_degree(num_group);
        for (auto [a, b]: edges) {
            if (nodes[a].group == nodes[b].group) continue;
            in_degree[nodes[b].group]++;
        }
        int ans = 0;
        for (int i=0; i<num_group; i++) {
            if (in_degree[i] == 0) ans++;
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}