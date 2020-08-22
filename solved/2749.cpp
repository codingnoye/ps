#include <iostream>
using namespace std;
const int M = 1000000;
const int P = 1500000;
int fibo[P];
int main() {
    unsigned long long n; cin>>n;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i=2; i<P; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= M;
    }
    cout<<(fibo[n%P]%M)<<endl;
}