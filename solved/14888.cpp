#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
int mn = 999999999;
int mx = -999999999;
int pl, mi, ml, dv;
void backtrack(int depth, int now) {
    if (depth==N-1) {
        mn = min(mn, now);
        mx = max(mx, now);
        return;
    }
    if (pl>0) {
        pl-=1;
        backtrack(depth+1, now+arr[depth+1]);
        pl+=1;
    }
    if (mi>0) {
        mi-=1;
        backtrack(depth+1, now-arr[depth+1]);
        mi+=1;
    }
    if (ml>0) {
        ml-=1;
        backtrack(depth+1, now*arr[depth+1]);
        ml+=1;
    }
    if (dv>0) {
        dv-=1;
        backtrack(depth+1, now/arr[depth+1]);
        dv+=1;
    }
}

int main() {
    cin>>N;
    arr.resize(N);
    for (int i=0; i<N; i++) cin>>arr[i];
    cin>>pl>>mi>>ml>>dv;
    backtrack(0, arr[0]);
    cout<<mx<<'\n'<<mn<<'\n';
}