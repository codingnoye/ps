#include <iostream>
using namespace std;
int primes[3402];
int pp[3402];
bool sieve[1000000001] = {false};
int main() {
    int primelen = 0;
    bool no;
    for (int i=2; i<31623; i++) {
        no = false;
        for (int j=0; j<primelen; j++) {
            if (i%primes[j]==0) {
                no = true;
                break;
            }
        }
        if (!no) {
            pp[primelen] = i*i;
            primes[primelen++] = i;
        }
    }
    for (int i=0; i<primelen; i++) {
        const int prime = pp[i];
        for (int j=2; j<=1000000000; j++) {
            const int jj = j*prime;
            if (jj > 1000000000) break;
            sieve[jj] = true;
        }
    }
    int x; cin>>x;
    int i=0;
    int j=0;
    while (i<=x) {
        if (!sieve[j++]) i++;
    }
    cout<<j-1<<endl;
}