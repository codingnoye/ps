#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000001;
int tree[1200000];
int* sorted;
int n, m, N, H;
int counter(int now, int size, int s, int e, int x) {
    if (size == 0) return 0;
    const int start = now%N;
    const int end = now%N+size;
    if (e<start || end<s) {
        return 0;
    }
    if (s<=start && end<=e) {
        return upper_bound(tree+now, tree+now+size, x) - (tree+now);
    }
    return counter(now+N, size/2, s, e, x) + counter(now+N+size/2, size/2, s, e, x);
}
void msort(int* arr_l, int* arr_r, int* res, int lsize, int rsize) {
    int li = 0;
    int ri = 0;
    for (int i=0; i<lsize+rsize; i++) {
        if (li==lsize) res[i] = arr_r[ri++];
        else if (ri==rsize) res[i] = arr_l[li++];
        else {
            if (arr_r[ri]<arr_l[li]) res[i] = arr_r[ri++];
            else res[i] = arr_l[li++];
        }
    }
}
void msort(int* arr_l, int* arr_r, int* res, int size) {
    msort(arr_l, arr_r, res, size, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    // make N=Cells of a line, H=Height
    H = 1;
    for (N=1; N<n; N<<=1) H++;
    // get array to bottom of tree
    int t;
    for (int i=0; i<n; i++) {
        cin>>t;
        tree[N*(H-1)+i]=t;
    }
    for (int i=n; i<N; i++) {
        tree[N*(H-1)+i] = MAX;
    }
    // build tree
    int s = 1;
    for (int h=0; h<H-1; h++) {
        for (int i=0; i<N; i+=s*2) {
            msort(tree+(H-h-1)*N+i, tree+(H-h-1)*N+i+s, tree+(H-h-2)*N+i, s);
        }
        s<<=1;
    }
    int I, J, K, l, r, now, v;
    for (int q=0; q<m; q++) {
        cin>>I>>J>>K;
        l = -1e9;
        r = 1e9;
        while (l<=r) {
            now = (l+r)/2;
            if (counter(0, N, I-1, J, now) < K) l = now+1;
            else r = now-1;
        }
        cout<<l<<'\n';
    }
}