#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double PI = acos(-1);
typedef complex<double> base;
using namespace std;
#define endl '\n';

const int N = 1<<20;
const int N2 = 1<<19;

base sosu[N];
base roots[N/2];
void fft(bool inv){
    int j = 0;
    for(int i=1; i<N; i++){
        int bit = N2;
        while(j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(sosu[i], sosu[j]);
    }
    double ang = 2 * acos(double(-1)) / N * (inv ? -1 : 1);
    for(int i=0; i<N2; i++){
        roots[i] = base(cos(ang * i), sin(ang * i));
    }
    for(int i=2; i<=N; i<<=1){
        int step = N / i;
        for(int j=0; j<N; j+=i){
            for(int k=0; k<i/2; k++){
                base u = sosu[j+k], v = sosu[j+k+i/2] * roots[step * k];
                sosu[j+k] = u+v;
                sosu[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<N; i++) sosu[i] /= N;
}
void pow(){
    fft(0);
    for(int i=0; i<N; i++) sosu[i] *= sosu[i];
    fft(1);
}


bool sieve[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (ll i=2; i<1000001; i++) {
        if (sieve[i] == false) {
            if (i != 2) sosu[(i-1)/2] = 1;
            for (ll j=i*i; j<1000001; j+=i) {
                sieve[j] = true;
            }
        }
    }

    pow();

    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        if (n==4) {
            cout<<1<<endl;
            continue;
        }
        int res = ceil((round(sosu[n/2-1].real())/2));
        cout<<res<<endl;
    }

    return 0;
}