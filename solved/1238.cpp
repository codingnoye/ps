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

const int INF = 999999999;
int distF[1001];
int distR[1001];
bool visited[1001];
vector<vector<ii>> graphF;
vector<vector<ii>> graphR;
struct cmp {
    bool operator()(ii a, ii b) {
        return a.second > b.second;
    }
};
void solve() {
    int N, M, X; cin>>N>>M>>X;
    graphF.resize(N+1);
    graphR.resize(N+1);
    for (int i=0; i<M; i++) {
        int S, E, T; cin>>S>>E>>T;
        graphF[S].push_back({E, T});
        graphR[E].push_back({S, T});
    }

    priority_queue<ii, vector<ii>, cmp> pq;
    for (int i=1; i<=N; i++) {
        distF[i] = INF;
        visited[i] = false;
    }
    distF[X] = 0;
    pq.push({X, 0});
    while (!pq.empty()) {
        ii now = pq.top();
        pq.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        //cout<<"now "<<now.first<<" dist "<<distF[now.first]<<endl;
        for (ii near: graphF[now.first]) {
            if (!visited[near.first]) {
                int newDist = distF[now.first] + near.second;
                if (newDist < distF[near.first]) {
                    distF[near.first] = newDist;
                    pq.push({near.first, newDist});
                }
            }
        }
        //cout<<now.first<<" is "<<distR[now.first]<<endl;
    }
    //cout<<endl;
    pq.push({X, 0});
    for (int i=1; i<=N; i++) {
        distR[i] = INF;
        visited[i] = false;
    }
    distR[X] = 0;
    while (!pq.empty()) {
        ii now = pq.top();
        pq.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        //cout<<"now "<<now.first<<" dist "<<distR[now.first]<<endl;
        for (ii near: graphR[now.first]) {
            if (!visited[near.first]) {
                int newDist = distR[now.first] + near.second;
                if (newDist < distR[near.first]) {
                    distR[near.first] = newDist;
                    pq.push({near.first, newDist});
                }
            }
        }
        //cout<<now.first<<" is "<<distR[now.first]<<endl;
    }
    int mx = 0;
    for (int i=1; i<=N; i++) {
        //cout<<i<<": "<<distR[i]<<"/"<<distF[i]<<endl;
        if (distR[i] != INF) {
            mx = max(distR[i]+distF[i], mx);
        }
    }
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}