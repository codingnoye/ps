#include <iostream>
using namespace std;

int main() {
    int N, K; cin>>N>>K;
    int res = 1;
    for (int i=N; i>N-K; i--) res *= i;
    for (int i=K; i>=1; i--) res /= i;
    cout<<res<<endl;
}