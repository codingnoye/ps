#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    queue<int> Q;
    for (int i=0; i<N; i++) {
        string cmd; cin>>cmd;
        if (cmd == "push") {
            int v; cin>>v;
            Q.push(v);
        } else if (cmd == "front") {
            if (Q.empty()) cout<<-1<<endl;
            else cout<<Q.front()<<endl;
        } else if (cmd == "back") {
            if (Q.empty()) cout<<-1<<endl;
            else cout<<Q.back()<<endl;
        } else if (cmd == "pop") {
           if (Q.empty()) cout<<-1<<endl;
            else {
                cout<<Q.front()<<endl;
                Q.pop();
            }
        } else if (cmd == "size") {
            cout<<Q.size()<<endl;
        } else if (cmd == "empty") {
            cout<<Q.empty()<<endl;
        }
    }
}