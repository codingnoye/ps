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

bool visited[1000001];
void solve() {
    int F, S, G, U, D; cin>>F>>S>>G>>U>>D;
    queue<ii> q;
    q.push({S, 0});
    while (!q.empty()) {
        ii now = q.front();
        q.pop();
        if (now.first<=0 || now.first>F) continue;
        if (visited[now.first]) continue;
        visited[now.first] = true;
        if (now.first == G) {
            cout<<now.second<<endl;
            return;
        }
        q.push({now.first+U, now.second+1});
        q.push({now.first-D, now.second+1});
    }
    cout<<"use the stairs"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}