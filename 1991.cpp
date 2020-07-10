#include <iostream>
using namespace std;

int graph[2][27] = {0};
void preorder(int node) {
    if (node == 0) return;
    cout<<(char)('A'+node-1);
    preorder(graph[0][node]);
    preorder(graph[1][node]);
}
void inorder(int node) {
    if (node == 0) return;
    inorder(graph[0][node]);
    cout<<(char)('A'+node-1);
    inorder(graph[1][node]);
}
void postorder(int node) {
    if (node == 0) return;
    postorder(graph[0][node]);
    postorder(graph[1][node]);
    cout<<(char)('A'+node-1);
}
int main() {
    int n; cin>>n;
    char a, b, c;
    for (int i=1; i<=n; i++) {
        cin>>a>>b>>c;
        graph[0][a-'A'+1] = b=='.'?0:b-'A'+1;
        graph[1][a-'A'+1] = c=='.'?0:c-'A'+1;
    }
    preorder(1);
    cout<<endl;
    inorder(1);
    cout<<endl;
    postorder(1);
    cout<<endl;
}