#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int mat[100][100] = {0};
bool complete[100] = {false};
bool visited[100];

void dfs(int now, int from) {
    if (visited[now]) return;
    visited[now] = true;
    if (complete[now]) {
        for (int i=0; i<N; i++) {
            if (mat[now][i] == 1)
                mat[from][i] = 1;
        }
        return;
    }
    for (int i=0; i<N; i++) {
        if (mat[now][i] == 1) {
            mat[from][i] = 1;
            dfs(i, from);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cin>>mat[y][x];
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) visited[j] = false;
        dfs(i, i);
        complete[i] = true;
    }
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            cout<<mat[y][x]<<" ";
        }
        cout<<'\n';
    }
}