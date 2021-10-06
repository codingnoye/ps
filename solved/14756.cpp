#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

const double PI = acos(-1);
typedef complex<double> cpx;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

void fft(vector <cpx> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        cpx wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            cpx w(1);
            for (int j=0;j<len/2;j++){
                cpx u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
 
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <cpx> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

void solve() {
    ll SW, TW, H, V; cin>>SW>>TW>>H>>V;
    vector<vector<int>> sky;
    vector<vector<int>> scope;
    sky.resize(H);
    for (int y=0; y<H; y++) {
        sky[y].resize(SW);
        for (int x=0; x<SW; x++) {
            cin>>sky[y][x];
        }
    } 
    scope.resize(H);
    for (int y=0; y<H; y++) {
        scope[y].resize(TW);
        for (int x=0; x<TW; x++) {
            cin>>scope[y][TW-1-x];
        }
    }
    vector<vector<int>> C;
    C.resize(H);
    for (int y=0; y<H; y++) {
        multiply(sky[y], scope[y], C[y]);
    }
    int res = 0;
    for (int x=TW-1; x<SW; x++) {
        ll nowsum = 0;
        for (int y=0; y<H; y++) {
            nowsum += C[y][x];
        }
        if (nowsum > V) res++;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}