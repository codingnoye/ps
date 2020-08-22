#include <iostream>
using namespace std;

int main() {
    int N; cin>>N;
    int now, last = 0;
    unsigned long long res = 0;
    while(N--) {
        cin>>now;
        if (now<last) {
            res += last-now;
            now += last-now;
        }
        last = now;
    }
    cout<<res<<endl;
}