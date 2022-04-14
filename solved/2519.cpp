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

struct Point{
    ll x;
    ll y;
    Point(ll x=0, ll y=0) : x(x), y(y){}    
};
bool operator< (Point A, Point B) {
    return pair{A.x, A.y} < pair{B.x, B.y};
}

// a, b, c 순서로 Counter clockwise라면 양수
// 절대값에 2를 나누면 면적
ll ccw(Point a, Point b, Point c, bool sign_only=false) {
    ll val = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
    if (sign_only && val!=0) return val/abs(val);
    return val;
}

// 선분 교차
bool is_intersect(Point A1, Point A2, Point B1, Point B2) {
    ll ccw1 = ccw(A1, A2, B1, true)*ccw(A1, A2, B2, true);
    ll ccw2 = ccw(B1, B2, A1, true)*ccw(B1, B2, A2, true);
    if (ccw1 == 0 && ccw2 == 0) {
        if (A2 < A1) swap(A1, A2);
        if (B2 < B1) swap(B1, B2);
        return A2 < B1 || B2 < A1;
    }
    return ccw1 <= 0 && ccw2 <= 0;
}

int N;
int s(int n) {
    return (6*N+n)%(6*N);
}
void solve() {
    cin>>N;
    vector<pair<Point, Point>> lines(3*N);
    init(6*N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            int a, b, c, d; cin>>a>>b>>c>>d;
            lines[3*i+j] = {{a, b}, {c, d}};
        }
        nodes[s(~(3*i+0))].adj.push_back(3*i+1);
        nodes[s(~(3*i+0))].adj.push_back(3*i+2);
        nodes[s(~(3*i+1))].adj.push_back(3*i+0);
        nodes[s(~(3*i+1))].adj.push_back(3*i+2);
        nodes[s(~(3*i+2))].adj.push_back(3*i+0);
        nodes[s(~(3*i+2))].adj.push_back(3*i+1);
    }

    for (int i=0; i<3*N; i++) {
        for (int j=0; j<3*N; j++) {
            if (i==j) continue;
            if (is_intersect(lines[i].first, lines[i].second, lines[j].first, lines[j].second)) {
                nodes[i].adj.push_back(s(~j));
                nodes[j].adj.push_back(s(~i));
            }
        }
    }

    for (int i=0; i<3*N; i++) {
        if (nodes[i].label == 0) dfs(i);
        if (nodes[s(~i)].label == 0) dfs(s(~i));
    }

    bool can = 1;
    for (int i=0; i<3*N; i++) {
        if (nodes[i].group == nodes[s(~i)].group) {
            can = 0;
            break;
        }
    }
    if (can) {
        vector<vector<int>> adj(groups.size());
        vector<pair<int, int>> toposort;
        for (int i=0; i<3*N; i++) {
            toposort.push_back({nodes[i].group, i});
            toposort.push_back({nodes[s(~i)].group, ~i});
        }
        // SCC 번호의 역순으로 조회하면 toposort의 노드 방문 순서
        // toposort 순서로, 먼저 방문하는 노드를 false로 지정
        sort(toposort.rbegin(), toposort.rend());
        for (auto [group, id]: toposort) {
            auto& node = nodes[s(id)];
            if (node.value == -1) {
                node.value = 0;
                nodes[s(~id)].value = 1;
            }
        }
        int removed = 0;
        vector<int> removed_items;
        for (int i=0; i<3*N; i++) {
            if (nodes[i].value == 0) removed_items.push_back(i+1);
        }
        cout<<removed_items.size()<<endl;
        sort(removed_items.begin(), removed_items.end());
        for (auto item: removed_items) cout<<item<<' ';
    } else {
        cout<<-1<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}