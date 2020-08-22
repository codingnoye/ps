#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N; cin>>N;
    deque<int> dq;
    for (int i=1; i<=N; i++) {
        dq.push_back(i);
    }
    while (N!=1) {
        dq.pop_front();
        if (dq.size()==1) break;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<dq.front()<<endl;
}