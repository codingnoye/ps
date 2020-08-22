#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > want;
int notebook[101] = {0};
bool visited[101];
const int EMPTY = 0;
bool matching(int man) {
    if (visited[man]) return false;
    visited[man] = true;
    for (int i=0; i<want[man].size(); i++) {
        int R = want[man][i];
        if (notebook[R] == EMPTY || matching(notebook[R])) {
            notebook[R] = man;
            return true;
        }
    }
    return false;
}
int main() {
    int N, M; cin>>N>>M;
    want.resize(N+1);
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        want[a].push_back(b);
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) visited[j] = false;
        matching(i);
    }
    int cnt = 0;
    for (int i=1; i<=N; i++) if (notebook[i]) cnt++;
    cout<<cnt<<endl;
}