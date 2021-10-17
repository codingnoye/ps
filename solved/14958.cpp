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
    int L1, L2; cin>>L1>>L2;
    string S1; cin>>S1;
    string S2; cin>>S2;
    
    vector<cpx> UR(L1), UP(L1), US(L1);
    vector<cpx> LR(L1), LP(L1), LS(L1);
    for (int i=0; i<L1; i++) {
        char c = S1.at(i);
        if (c=='R') UR[i] = 1;
        else if (c=='P') UP[i] = 1;
        else US[i] = 1;
    }
    for (int i=0; i<L2; i++) {
        char c = S2.at(L2-1-i);
        if (c=='R') LR[i] = 1;
        else if (c=='P') LP[i] = 1;
        else LS[i] = 1;
    }
    vector<cpx> RP = multiply(UR, LP);
    vector<cpx> PS = multiply(UP, LS);
    vector<cpx> SR = multiply(US, LR);
    int maxv = -1;
    for (int i=L2-1; i<L2-1+L1; i++) {
        int v = (int)RP[i].real() + (int)PS[i].real() + (int)SR[i].real();
        if (maxv < v) maxv = v;
    }
    cout<<maxv<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}