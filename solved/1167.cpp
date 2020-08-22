#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<vector<pair<int, int> > > dist;

int* dst;
// dist[from] = {to, d}

pair<int, int> find_far(int V, int from) {
    queue<pair<int, int> > q;
    bool visited[V];
    for (int i=0; i<V; i++) {
        dst[i] = -1;
        visited[i] = false;
    }
    visited[from] = true;
    q.push(make_pair(from, 0));
    while (!q.empty()) {
        int now = q.front().first;
        int d = q.front().second;
        q.pop();
        dst[now]=d;
        for (int i=0; i<dist[now].size(); i++) {
            if (!visited[dist[now][i].first]) {
                q.push(make_pair(dist[now][i].first, d+dist[now][i].second));
                visited[dist[now][i].first] = true;
            }
        }
    }
    int mx = 0;
    int mxi = -1;
    for (int i=0; i<V; i++) {
        if (mx<dst[i]) {
            mxi = i;
            mx = dst[i];
        }
    }
    return make_pair(mx, mxi);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int V;
    cin>>V;
    dst = new int[V];
    int a, b;
    dist.resize(V);
    for (int i=0; i<V; i++) {
        int c; cin>>c;
        vector<pair<int, int> > now;
        while (true) {
            cin>>a;
            if (a==-1) break;
            cin>>b;
            now.push_back(make_pair(a-1, b));
        }
        dist[c-1] = now;
    }
    int far = find_far(V, 0).second;
    int D = find_far(V, far).first;
    cout<<D<<endl;
}