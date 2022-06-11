#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

const int INF = 987654321;
const int MAXN = 1001;
int dist[MAXN][MAXN];
int main() {
    fastio;

    int N; cin>>N;
    int M; cin>>M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i=0; i<M; i++) {
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        if (c==0) c = INF;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 0; k < N; k++) { // 경유 노드
        for (int i = 0; i < N; i++) { // 출발 노드
            for (int j = 0; j < N; j++) { // 도착 노드
                if (i==j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<(dist[i][j]==INF?0:dist[i][j])<<' ';
        }
        cout<<endl;
    }
}