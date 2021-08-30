#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int cnt[200001];
int used[200001];
stack<int> stacks[200001];
void solve() {
    int N, M; cin>>N>>M;
    for (int m=1; m<=M; m++) {
        int k; cin>>k;
        for (int i=0; i<k; i++) {
            int x; cin>>x;
            stacks[m].push(x);
        }
    }
    int balls = 2*N;
    queue<int> todo;
    while (balls > 0) {
        bool found = false;
        for (int i=1; i<=M; i++) {
            todo.push(i);
            while (!todo.empty()) {
                int j = todo.front();
                todo.pop();
                if (stacks[j].empty()) continue;
                int now = stacks[j].top();
                if (cnt[now] == 0) {
                    cnt[now] = j;
                } else if (j != cnt[now]){
                    todo.push(cnt[now]);
                    todo.push(j);
                    stacks[j].pop();
                    stacks[cnt[now]].pop();
                    cnt[now] = 0;
                    found = true;
                    balls -= 2;
                }
            }
        }
        if (!found) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}