#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull; 
ull tree[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ull M;
    cin>>N>>M;
    for (int i=0; i<N; i++) cin>>tree[i];
    ull l=0;
    ull r = 2000000001;
    while (l<r) {
        const ull m = (l+r)/2;
        ull now=0;
        for (int i=0; i<N; i++) {
            now += (m<=tree[i])?tree[i]-m:0;
        }
        //cout<<m<<" "<<now<<endl;
        if (now<=M) r = m-1;
        else l = m+1;
    }
    cout<<l<<'\n';
}