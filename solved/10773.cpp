#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K; cin>>K;
    stack<int> S;
    while (K--) {
        int x; cin>>x;
        if (x) S.push(x);
        else S.pop();
    }
    while (!S.empty()) {
        K += S.top();
        S.pop();
    }
    cout<<(K+1)<<endl;
}