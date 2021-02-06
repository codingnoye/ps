#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;
struct node{
    int value;
    node* left;
    node* right;
    node* parent;
    node(int v, node* l, node* r, node* p) : value(v), left(l), right(r), parent(p) {}
};

void printTree(node* n) {
    if (n->left) printTree(n->left);
    if (n->right) printTree(n->right);
    cout<<(n->value)<<endl;
}

void solve() {
    int x; cin>>x;
    node head = {x, NULL, NULL, NULL};
    while(true) {
        int x; cin>>x;
        if (cin.eof()) break;
        node* now = new node(x, NULL, NULL, NULL);
        node* last = &head;
        while (true) {
            if (now->value < last->value) {
                if (!(last->left)) {
                    last->left = now;
                    now->parent = last;
                    last = now;
                    break;
                } else {
                    last = last->left;
                }
            } else {
                if (!(last->right)) {
                    last->right = now;
                    now->parent = last;
                    last = now;
                    break;
                } else {
                    last = last->right;
                }
            }
        }
    }
    printTree(&head);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}