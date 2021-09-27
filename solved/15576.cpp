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
    string sa, sb; cin>>sa>>sb;

    int sasize = sa.size();
    int sbsize = sb.size();
    vector<cpx> A(sasize), B(sbsize);
    for (int i=0; i<sasize; i++) A[i] = (sa[sasize-1-i])-'0';
    for (int i=0; i<sbsize; i++) B[i] = (sb[sbsize-1-i])-'0';
    vector<cpx> C = multiply(A, B);
    vector<int> D(C.size());
    for (int i=0; i<C.size(); i++) {
        int now = (int)C[i].real();
        D[i] = now;
    }
    for (int i=0; i<C.size()-1; i++) {
        int now = D[i];
        D[i] = now%10;
        D[i+1] += now/10;
    }
    bool first = true;
    for (int i=C.size()-1; i>=0; i--) {
        if (!(first && D[i]==0)) {
            cout<<D[i];
            first = false;
        } else if (first && i==0) {
            cout<<D[i];
        }
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}