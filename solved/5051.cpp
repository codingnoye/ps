#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    if(n == 1) return;
 
    vector<cpx> even(n/2), odd(n/2);
    for(int i = 0; i < n; ++i)
        (i%2 ? odd : even)[i/2] = f[i];
 
    FFT(even, w*w);
    FFT(odd, w*w);
 
    cpx wp(1, 0);
    for(int i = 0; i < n/2; ++i){
        // f(x) = f_even(x^2) + x * f_odd(x^2)
        f[i] = even[i] + wp*odd[i];
        // f(-x) = f_even(x^2) - x * f_odd(x^2)
        f[i + n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);
 
    cpx w(cos(2*PI/n), sin(2*PI/n));
 
    FFT(a, w);
    FFT(b, w);
 
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
 
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

void solve() {
    int N; cin>>N;
    vector<cpx> A(N), B(N);
    
    vector<int> S(N);
    for (ll i=1; i<N; i++) {
        ll now = (i*i) % N;
        A[now] += 1;
        B[now] += 1;
        ll now2 = (i*i*2) % N;
        S[now2] += 1;
    }
    vector<cpx> C = multiply(A, B);
    ll sum = 0;
    ll same = 0;
    for (ll i=1; i<N; i++) {
        ll now = (i*i) % N;
        sum += (int)C[now].real();
        sum += (int)C[now+N].real();

        same += S[now];
    }
    ll res = (sum - same)/2 + same;
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}