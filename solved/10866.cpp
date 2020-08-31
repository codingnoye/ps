#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N; cin>>N;
    deque<int> dq;
    while (N--) {
        string op; int x; cin>>op;
        if (op=="push_back") {
            cin>>x;
            dq.push_back(x);
        } else if (op=="push_front") {
            cin>>x;
            dq.push_front(x);
        } else if (op=="pop_front") {
            if (dq.empty()) cout<<-1<<endl;
            else {
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        } else if (op=="pop_back") {
            if (dq.empty()) cout<<-1<<endl;
            else {
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        } else if (op=="size") {
            cout<<dq.size()<<endl;
        } else if (op=="empty") {
            cout<<dq.empty()<<endl;
        } else if (op=="front") {
            if (dq.empty()) cout<<-1<<endl;
            else cout<<dq.front()<<endl;
        } else if (op=="back") {
            if (dq.empty()) cout<<-1<<endl;
            else cout<<dq.back()<<endl;
        }
    }
}