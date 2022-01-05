#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>
using namespace std;
#define endl '\n'
typedef long long ll;

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

int cnt = 0;
void solve() {
    vector<cpx> A(200002), C(200002);
    set<int> B;

    int N1; cin>>N1;
    for (int i=0; i<N1; i++) {
        int x; cin>>x;
        A[x+30000] = cpx(1, 0);
    }
    int N2; cin>>N2;
    for (int i=0; i<N2; i++) {
        int x; cin>>x;
        B.insert(x*2);
    }
    int N3; cin>>N3;
    for (int i=0; i<N3; i++) {
        int x; cin>>x;
        C[x+30000] = cpx(1, 0);
    }
    vector<cpx> X = multiply(A, C);
    
    for (int i=0; i<X.size(); i++) {
        int now = (int)(X[i].real());
        if (now>0)
            if (B.find((i-60000)) != B.end()) {
                // cout<<i<<' '<<now<<' '<<((i-60000)/2)<<endl;
                cnt+=now;
            }
    }
    cout<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}