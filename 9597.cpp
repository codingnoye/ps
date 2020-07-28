#include <iostream>
#include <vector>
using namespace std;

int want[1001][1001];
int room[1001];
int siz[1001];
bool visited[1001];
const int EMPTY = 0;
bool matching(int cow) {
    if (visited[cow]) return false;
    visited[cow] = true;
    for (int i=0; i<siz[cow]; i++) {
        int R = want[cow][i];
        if (room[R] == EMPTY || matching(room[R])) {
            room[R] = cow;
            return true;
        }
    }
    return false;
}
int main() {
    int T; cin>>T;
    while (T--) {
        int N, M; cin>>M>>N;
        for (int k=1; k<=M; k++) room[k] = 0;
        for (int n=1; n<=N; n++) {
            int a, b; cin>>a>>b;
            siz[n] = b-a+1;
            for (int s=a; s<=b; s++) {
                want[n][s-a] = s;
            }
        }
        int tmp = 0;
        for (int n=1; n<=N; n++) {
            for (int k=1; k<=N; k++) visited[k] = false;
            matching(n);
        }
        int cnt = 0;
        for (int m=1; m<=M; m++) if (room[m]) cnt++;
        cout<<cnt<<endl;   
    }
}