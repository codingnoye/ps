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

void init(int n) {
    num_label = 0;
    num_group = 0;
    while (!st.empty()) st.pop();
    nodes.clear();
    nodes.resize(n);
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

int N, M;
int s(int n) {
    return (2*(N+M)+n)%(2*(N+M));
}
void solve() {
    int T; cin>>T;
    while (T--){
        int K; cin>>N>>M>>K;
        init(2*(N+M));

        for (int i=0; i<K; i++) {
            int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
            int x_move = x2-x1;
            int y_move = y2-y1;
            x1-=1; x2-=1; y1-=1; y2-=1;
            y1 = N+y1;
            y2 = N+y2;
            if (x_move < 0) {
                y1 = ~y1;
                y2 = ~y2;
            }
            if (y_move < 0) {
                x1 = ~x1;
                x2 = ~x2;
            }
            nodes[s(~x1)].adj.push_back(s(x2));
            nodes[s(~x1)].adj.push_back(s(y1));
            nodes[s(~x2)].adj.push_back(s(x1));
            nodes[s(~x2)].adj.push_back(s(y2));
            nodes[s(~y1)].adj.push_back(s(x1));
            nodes[s(~y1)].adj.push_back(s(y2));
            nodes[s(~y2)].adj.push_back(s(x2));
            nodes[s(~y2)].adj.push_back(s(y1));
        }

        for (int i=0; i<N+M; i++) {
            if (nodes[i].label == 0) dfs(i);
            if (nodes[s(~i)].label == 0) dfs(s(~i));
        }

        bool can = 1;
        for (int i=0; i<N+M; i++) {
            if (nodes[i].group == nodes[s(~i)].group) {
                can = 0;
                break;
            }
        }
        if (can) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}