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

int parent[3001];

void unite(int x, int y) {
    while (parent[x] != parent[y]) {
        if (parent[y] < parent[x]) swap(x, y);
        if (x==parent[x]) {
            parent[x] = parent[y];
            break;
        }
        int z = parent[x];
        parent[x] = parent[y];
        x = z;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int dist(int x0, int y0, int x1, int y1) {
    int xd = x1-x0;
    int yd = y1-y0;
    return xd*xd+yd*yd;
}

void solve() {
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        vector<pair<ii, int>> nodes;
        for (int i=0; i<N; i++) {
            int x, y, r; cin>>x>>y>>r;
            parent[i] = i;
            nodes.push_back({{x, y}, r});
        }
        int answer = N;
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                pair<ii, int> n1 = nodes[i];
                pair<ii, int> n2 = nodes[j];
                if (dist(n1.first.first, n1.first.second, n2.first.first, n2.first.second) <= (n1.second+n2.second)*(n1.second+n2.second)) {
                    if (find(i) != find(j)) {
                        unite(i, j);
                        answer--;
                    }
                }
            }
        }
        cout<<answer<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}