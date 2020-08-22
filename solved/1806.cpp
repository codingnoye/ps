#include <iostream>
using namespace std;

int arr[100001];
int main() {
    int N, S; cin>>N>>S;
    arr[0] = 0;
    for (int i=1; i<=N; i++) cin>>arr[i];
    int now = 0;
    int l = 0, r = 0;
    int mn = 100001;
    while (r<=N || l<=N) {
        if (now < S && r <= N) {
            now += arr[++r];
        } else {
            now -= arr[++l];
        }
        if (now >= S) {
            //cout<<"now "<<now<<" len "<<(r-l)<<endl;
            mn = mn<(r-l)?mn:(r-l);
        }
    }
    cout<<(mn==100001?0:mn)<<endl;
}