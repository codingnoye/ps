#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    int dasom; cin>>dasom;

    priority_queue<int> enemies;
    for (int i=1; i<N; i++) {
        int x; cin>>x;
        enemies.push(x);
    }

    int need = 0;
    while (!enemies.empty()) {
        int max_enemy = enemies.top(); enemies.pop();
        
        if (max_enemy < dasom) break;
        need++;
        dasom++;
        enemies.push(max_enemy - 1);
    }
    cout<<need<<endl;
}