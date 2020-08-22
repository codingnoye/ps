#include <iostream>
using namespace std;

int main() {
    int N, M; cin>>N>>M;
    int arr[N];
    for (int i=0; i<N; i++) cin>>arr[i];
    int mx=0, mxi, tmp;
    for (int a=0; a<N-2; a++) for (int b=a+1; b<N-1; b++) for (int c=b+1; c<N; c++) {
        tmp = arr[a]+arr[b]+arr[c];
        if (mx<tmp && tmp<=M) mx = tmp;
    }
    cout<<mx<<endl;
}