#include <iostream>
#include <cstring>
using namespace std;

int nodes[100001];
bool visited[100001];
bool checked[100001];
int res;
void dfs(int now) {
    const int next = nodes[now];
    //cout<<now<<","<<next<<endl;
    visited[now] = true;
    if (!checked[next]) {
        if (visited[next]) {
            for (int i=next; i!=now; i=nodes[i]) {
                //cout<<"/"<<i<<endl;
                res++;
            }
            res++;
        } else {
            dfs(next);
        }
    }
    checked[now] = true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        res = 0;
        memset(visited, false, sizeof(visited));
        memset(checked, false, sizeof(checked));
        for (int i=1; i<=n; i++) {
            cin>>nodes[i];
        }
        for (int i=1; i<=n; i++) {
            //cout<<"i is "<<i<<endl;
            if (!visited[i]) dfs(i);
        }
        cout<<(n-res)<<'\n';
    }
}