#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// #define endl '\n'
typedef long long ll;

struct Node {
    Node (int num): n(num) {}
    int n;
    int L = 0;
    int R = 0;
    vector<Node*> childs;
    int total_terms;
};

vector<vector<int>> G;

Node* nodes[200001];

bool visited[200001];
void make_tree(Node* root) {
    visited[root->n] = true;
    for (int n: G[root->n]) {
        if (!visited[n]) {
            Node* child = new Node(n);
            nodes[n] = child;
            root->childs.push_back(child);
            make_tree(child);
        }
    }
}

int n_term = 0;

int count_terms(Node* root) {
    if (root->childs.size() == 0) {
        root->total_terms = 1;
        return 1;
    }
    int res = 0;
    for (Node* child: root->childs) {
        res += count_terms(child);
    }
    root->total_terms = res;
    return res;
}

void set_range(Node* root, int L, int R) {
    root->L = L;
    root->R = R;
    int p = L;
    for (int i=0; i<root->childs.size(); i++) {
        Node* child = root->childs[i];
        set_range(child, p, p + (child->total_terms)-1);
        p = p + (child->total_terms);
    }
}

void solve() {
    int N; cin>>N;
    G.resize(N+1);
    for (int i=0; i<N-1; i++) {
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Node* root = new Node(1);
    nodes[1] = root;
    make_tree(root);
    n_term = count_terms(root);
    set_range(root, 1, n_term);
    for (int i=1; i<=N; i++) {
        cout<<(nodes[i]->L)<<' '<<(nodes[i]->R)<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}