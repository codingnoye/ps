#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 200;
int capacity[MAX][MAX] = { 0 };
vector<int> v[MAX];

int flow[MAX][MAX] = { 0, };

int make_flow(int s, int e, vector<int>& path) {
    int cost = 2e9;
    int cur = e;
    while (cur != s) {
        cost = min(cost, capacity[path[cur]][cur] - flow[path[cur]][cur]);
        cur = path[cur];
//        cout<<cur<<"<-";
    }
//    cout<<s<<endl;
    cur = e;
    while (cur != s) {
        flow[path[cur]][cur] += cost;
        flow[cur][path[cur]] -= cost;
        
        cur = path[cur];
    }
    return cost;
}

int bfs(int s, int e) {
    vector<int> path(MAX, -1);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int y = v[x][i];
            if (capacity[x][y] - flow[x][y] > 0 && path[y] < 0) {
                q.push(y);
                path[y] = x;
                if (y == e) {
                    return make_flow(s, e, path);
                }
            }
        }
    }
    return 0;
}

int edmonds_karp(int s, int e) {
    int maxflow = 0;
    while (1) {
        int c = bfs(s, e);
        if (c > 0) {
            maxflow += c;
        }
        else
        {
            break;
        }
    }
    return maxflow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        int broken = 0;
        cin >> n >> m;

        for (int i = 0; i < 200; i++){
            for (int j = 0; j < 200; j++){
                flow[i][j] = 0;
                capacity[i][j] = 0;
            }
            v[i].clear();
        }

        char a;
        int input[20][20] = { 0 };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a == 'x') {
                    input[i][j] = 1;
                    broken++;
                }
                else {
                    input[i][j] = 0;
                }
            }
        }

        int idx[MAX][MAX] = { 0, };
        int A = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j += 2)
            {
                capacity[0][A]=1;
                v[0].push_back(A);
                idx[i][j] = A++;
            }
        }

        int B = A;
        int end = n * m + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j += 2) {
                v[B].push_back(end);
                capacity[B][end] = 1;
                idx[i][j] = B++;
            }
        }

        int dx[6] = { -1,-1,0,0,1,1 };
        int dy[6] = { -1,1,-1,1,-1,1 };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j += 2) {
                for (int k = 0; k < 6; k++) {
                    int X = dx[k] + i;
                    int Y = dy[k] + j;
                    if (X >= 0 && Y >= 0 && X < n && Y < m &&
                        input[X][Y]==0 && input[i][j]==0) {
                        capacity[idx[i][j]][idx[X][Y]] = 1;
                        v[idx[i][j]].push_back(idx[X][Y]);
                        v[idx[X][Y]].push_back(idx[i][j]);
                    }
                }
            }
        }

        int ret = edmonds_karp(0, end);
//        int t=0;
//        for (int i = 0; i < A; i++){
//            t = edmonds_karp(i, end);
//            if(t>0)
//            {
//                ret++;
//            }
//        }
        cout << n * m - ret - broken << endl;
    }
}
