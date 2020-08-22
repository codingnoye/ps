#include <iostream>
#include <vector>
using namespace std;
bool sieve[4300001] = {false};
int main() {
    vector<int> primes;
    for (int i=2; i<4300001; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (int j=i*2; j<4300001; j+=i) sieve[j] = true;
    }
    int N; cin>>N;
    int i = 0, j = 0;
    int sum = primes[0];
    int cnt = 0;
    while (i<=j) {
        if (sum == N) cnt++;
        if (sum>N) {
            sum -= primes[i++];
        } else {
            sum += primes[++j];
        }
    }
    cout<<cnt<<endl;
}