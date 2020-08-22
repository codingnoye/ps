#include <iostream>
#include <vector>
using namespace std;

int sharks[51][3];
int eater[51] = {0};
int siz[51];
bool visited[1001];
int N;
const int EMPTY = 0;
int matching(int shark) {
    if (shark == 0) return 0;
    if (visited[shark]) return 0;
    visited[shark] = true;
    for (int i=1; i<=N; i++) {
        if (shark == i) continue;
        if (sharks[shark][0] == sharks[i][0] && sharks[shark][1] == sharks[i][1] && sharks[shark][2] == sharks[i][2] && shark<i) continue;
        if (sharks[shark][0] >= sharks[i][0] && sharks[shark][1] >= sharks[i][1] && sharks[shark][2] >= sharks[i][2]) {
            if (eater[i] == EMPTY || matching(eater[i])) {
                eater[i] = shark;
                return i;
            }
        }
    }
    return 0;
}
int main() {
    cin>>N;
    for (int n=1; n<=N; n++) {
        cin>>sharks[n][0]>>sharks[n][1]>>sharks[n][2];
    }
    for (int n=1; n<=N; n++) {
        for (int k=1; k<=N; k++) visited[k] = false;
        matching(n);
    }
    for (int n=1; n<=N; n++) {
        for (int k=1; k<=N; k++) visited[k] = false;
        matching(n);
    }
    int cnt = 0;
    for (int i=1; i<=N; i++) if (eater[i]==0) cnt++;
    cout<<cnt<<endl;
}