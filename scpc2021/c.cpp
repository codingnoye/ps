#include <bits/stdc++.h>
<<<<<<< HEAD
#define fastio cin.tie(0)->sync_with_stdio(0)
// #define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> graph_raw; // vec<vec<dest, label>>
vector<vector<pair<int, int>>> graph; // vec<vec<dest, weight>>

bool dfs(int i, vector<bool>& visited) {
    if (visited[i]) return true;
    visited[i] = true;
    for (auto& [j, weight] : graph[i]) {
        if (weight == 0 && dfs(j, visited)) return true;
    }
    return false;
}

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int ans = 0;
        int N, M, K; cin>>N>>M>>K;

        graph_raw = vector<vector<pair<int, int>>>(N);
        graph = vector<vector<pair<int, int>>>(N);
        for (int i=0; i<M; i++) {
            int u, v; string label; cin>>u>>v>>label;
            graph_raw[u-1].push_back({v-1, label[0]-'A'});
        }

        for (int i=0; i<N; i++) {
            for (auto& [j, ij_label] : graph_raw[i]) {
                for (auto& [k, jk_label]: graph_raw[j]) {
                    if (i==k) continue;
                    if ((ij_label+1)%3 == jk_label || K==-1) {
                        graph[i].push_back({k, 0});
                    } else {
                        graph[i].push_back({k, 1});
                    }
                }
            }
        }

        vector<bool> visited(N, false);
        for (int i=0; i<N; i++) {
            if (visited[i]) continue;
            if (dfs(i, visited)) {
                ans = -1;
=======
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        ll ans = 0;

        int N; cin>>N;
        vector<pair<ll, ll>> points(N); // y, x

        map<ll, vector<ll>> ytox, xtoy;
        ff(i, 0, N) {
            ll y, x; cin>>y>>x;
            points[i] = {y, x};
            ytox[y].push_back(x);
            xtoy[x].push_back(y);
        }

        ll rem_y, rem_x;
        bool rem_exist = false;

        for (auto& [y, xs] : ytox) {
            if (xs.size()%2 == 1) {
                rem_y = y;
                rem_exist = true;
                break;
            }
        }
        for (auto& [x, ys] : xtoy) {
            if (ys.size()%2 == 1) {
                rem_x = x;
                rem_exist = true;
>>>>>>> 2d8c2d02d42975dbb79638bed5e25557b3f26cd5
                break;
            }
        }

<<<<<<< HEAD
        if (ans != 1) {
            // find max node length on route length K
            int max_length = 0;
        }

        cout<<"Case #"<<t<<endl<<ans<<endl;
=======
        ll res = 0;
        for (auto& [y, xs] : ytox) {
            sort(xs.begin(), xs.end());
            for (int i=0; i<xs.size();) {
                if (rem_exist && y == rem_y) {
                    if (xs[i] == rem_x) {
                        i+=1;
                        continue;
                    } else if (xs[i+1] == rem_x) {
                        res += xs[i+2] - xs[i];
                        i+=3;
                        continue;
                    }
                }
                res += xs[i+1] - xs[i];
                i += 2;
            }
        }
        for (auto& [x, ys] : xtoy) {
            sort(ys.begin(), ys.end());
            for (int i=0; i<ys.size();) {
                if (rem_exist && x == rem_x) {
                    if (ys[i] == rem_y) {
                        i+=1;
                        continue;
                    } else if (ys[i+1] == rem_y) {
                        res += ys[i+2] - ys[i];
                        i+=3;
                        continue;
                    }
                }
                res += ys[i+1] - ys[i];
                i += 2;
            }
        }
        cout<<"Case #"<<C<<endl<<res<<endl;
>>>>>>> 2d8c2d02d42975dbb79638bed5e25557b3f26cd5
    }
}