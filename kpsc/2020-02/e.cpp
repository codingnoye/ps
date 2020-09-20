#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> G;
bool visited[100001] = {false};

int check_group(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    int count = 0;
    //cout<<"started at "<<start<<endl;
    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        count++;
        //cout<<"now is "<<now<<" and count is "<<count<<endl;
        for (auto it=G[now].begin(); it!=G[now].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                Q.push(*it);
            }
        }
    }
    return count;
}

int main() {
    int N, M; cin>>N>>M;
    G.resize(N+1);
    while (M--) {
        int a, b; cin>>a>>b;
        G[a].insert(b);
        G[b].insert(a);
    }
    int res = 0;
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            int tmp = check_group(i);
            //cout<<tmp<<endl;
            res += tmp/2+1;
        }
    }
    cout<<res<<endl;
}