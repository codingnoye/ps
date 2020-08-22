#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int cnt = 0;
    unsigned long long now = 1;
    for (int i=n; i>0; i--) {
        now *= i;
        while (now%10 == 0) {
            now /= 10;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}