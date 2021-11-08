#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;
#define endl '\n'
typedef long long ll;

typedef complex<double> base;
void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	/* In NTT, let prr = primitive root. Then,
	int ang = ipow(prr, (mod - 1) / n);
	if(inv) ang = ipow(ang, mod - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
	}
	XOR Convolution : set roots[*] = 1.
	OR Convolution : set roots[*] = 1, and do following:
    if (!inv) {
        a[j + k] = u + v;
        a[j + k + i/2] = u;
    } else {
        a[j + k] = v;
        a[j + k + i/2] = u - v;
    }
	*/
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

void solve() {
    int N, M; cin>>N>>M;
    vector<ll> FU(N+1), FL(N+1), GU(M+1), GL(M+1);
    for (int i=0; i<=N; i++) {
        ll x; cin>>x;
        ll upper = x>>10;
        ll lower = x&((1<<10)-1);
        FL[i] = lower;
        FU[i] = upper;
    }
    for (int i=0; i<=M; i++) {
        ll x; cin>>x;
        ll upper = x>>10;
        ll lower = x&((1<<10)-1);
        GL[i] = lower;
        GU[i] = upper;
    }
    vector<ll> CA = multiply(FU, GU);
    vector<ll> CB = multiply(FU, GL);
    vector<ll> CC = multiply(FL, GU);
    vector<ll> CD = multiply(FL, GL);
    ll res = 0;
    for (int i=0; i<=N+M; i++) {
        ll x = 0;
        x += CA[i]<<20;
        x += (CB[i] + CC[i])<<10;
        x += CD[i];
        res ^= x;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}