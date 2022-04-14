#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

ll max_label = 0;
stack<int> st;
struct node {
    ll label = 0;
    bool finished = false;
    vector<int> adj;
};
vector<node> nodes;
vector<vector<ll>> SCC;

// 각 노드마다 d가 0이라면 dfs 실행
ll dfs(int n_id) {
    node& n = nodes[n_id];
	n.label = ++max_label; // 노드마다 고유한 번호를 할당 
	st.push(n_id); // 스택에 자기 자신을 삽입 
	
	ll parent = n.label;
	for(int a_id: n.adj) {
        node& a = nodes[a_id];
		if(a.label == 0) parent = min(parent, dfs(a_id)); // 방문하지 않은 이웃 
		else if(!a.finished) parent = min(parent, a.label); // 처리중인 이웃 
	}
	
	if(parent == n.label) { // 부모노드가 자기 자신인 경우 
		vector<ll> scc;
		while (true) {
			int t_id = st.top();
            node& t = nodes[t_id];
			st.pop();
			scc.push_back(t_id);
			t.finished = true;
			if(t_id == n_id) break;
		}
		SCC.push_back(scc);
	}
	
	// 자신의 부모 값 반환
	return parent; 
}

void solve() {
    int V, E; cin>>V>>E;
    nodes.resize(V);
    for (int i=0; i<E; i++) {
        int a, b; cin>>a>>b;
        nodes[a-1].adj.push_back(b-1);
    }
    for (int i=0; i<V; i++) {
        if (nodes[i].label == 0) dfs(i);
    }
    cout<<SCC.size()<<endl;
    for (auto& items: SCC) {
        sort(items.begin(), items.end());
    }
    sort(SCC.begin(), SCC.end());
    for (auto items: SCC) {
        for (auto item: items) {
            cout<<item+1<<' ';
        }
        cout<<-1<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}