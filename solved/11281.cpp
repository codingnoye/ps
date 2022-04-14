#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = 987654321;
struct node {
    int group = MAX;
    int label = 0;
    bool finished = false;
    vector<int> adj;
    int value = -1; // 0 = false, 1 = true
};
vector<node> nodes;

int num_label;
int num_group;
stack<int> st;

vector<vector<int>> groups; // 그룹으로 얻어야 할때

void init(int n) {
    num_label = 0;
    num_group = 0;
    while (!st.empty()) st.pop();
    nodes.resize(n);
    groups.clear(); // 그룹으로 얻어야 할때
}

// 각 노드마다 d가 0이라면 dfs 실행
int dfs(int n_id) {
    node& n = nodes[n_id];
	n.label = ++num_label; // 노드마다 고유한 번호를 할당 
	st.push(n_id); // 스택에 자기 자신을 삽입 
	
	int parent = n.label;
	for(int a_id: n.adj) {
        node& a = nodes[a_id];
		if(a.label == 0) parent = min(parent, dfs(a_id)); // 방문하지 않은 이웃 
		else if(!a.finished) parent = min(parent, a.label); // 처리중인 이웃 
	}
	
	if(parent == n.label) { // 부모노드가 자기 자신인 경우 
        vector<int> group;
		while (true) {
			int t_id = st.top();
            node& t = nodes[t_id];
            t.group = num_group;
            group.push_back(t_id); // 그룹으로 얻어야 할때
			st.pop();
			t.finished = true;
			if(t_id == n_id) break;
		}
        groups.push_back(group); // 그룹으로 얻어야 할때
        num_group++;
	}
	
	// 자신의 부모 값 반환
	return parent; 
}

int N;
int s(int n) {
    return ((2*N+1)+n)%(2*N+1);
}
void solve() {
    int M;
    cin>>N>>M;
    init(2*(N+1));

    vector<pair<int, int>> edges;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        nodes[s(-a)].adj.push_back(s(b));
        nodes[s(-b)].adj.push_back(s(a));
        edges.push_back({a, b});
    }

    for (int i=1; i<=N; i++) {
        if (nodes[i].label == 0) dfs(i);
        if (nodes[s(-i)].label == 0) dfs(s(-i));
    }

    bool can = 1;
    for (int i=1; i<=N; i++) {
        if (nodes[i].group == nodes[s(-i)].group) {
            can = 0;
            break;
        }
    }
    cout<<can<<endl;
    if (can) {
        vector<vector<int>> adj(groups.size());
        vector<pair<int, int>> toposort;
        for (int i=1; i<=N; i++) {
            toposort.push_back({nodes[i].group, i});
            toposort.push_back({nodes[s(-i)].group, -i});
        }
        // SCC 번호의 역순으로 조회하면 toposort의 노드 방문 순서
        // toposort 순서로, 먼저 방문하는 노드를 false로 지정
        sort(toposort.rbegin(), toposort.rend());
        for (auto [group, id]: toposort) {
            auto& node = nodes[s(id)];
            if (node.value == -1) {
                node.value = 0;
                nodes[s(-id)].value = 1;
            }
        }
        for (int i=1; i<=N; i++) {
            cout<<nodes[i].value<<' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}