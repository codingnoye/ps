#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<pair<int, int> > q;
    // time, position
    int n, k; cin>>n>>k;
    q.push(make_pair(0, n));
    bool visited[100001] = {false};
    int t;
    while (true) {
        t = q.front().first;
        n = q.front().second;
        q.pop();
        if (n>100000 || n<0 || visited[n]) continue;
        visited[n] = true;
        if (n==k) break;
        q.push(make_pair(t+1, n+1));
        q.push(make_pair(t+1, n-1));
        q.push(make_pair(t+1, n*2));
    }
    cout<<t<<endl;
}