#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;
    int arr[N];
    int firstplus = -1;
    for (int i=0; i<N; i++) {
        cin>>arr[i];
        if (firstplus==-1 && arr[i]>=0) firstplus = i;
    }
    if (firstplus==0) cout<<arr[0]<<" "<<arr[1]<<endl;
    else if (firstplus==-1) cout<<arr[N-2]<<" "<<arr[N-1]<<endl;
    else {
        int minval = 2000000001;
        int mina, minb;
        if (firstplus<=N/2) {
            for (int i=0; i<firstplus; i++) {
                int found = lower_bound(arr, arr+N, -arr[i]) - arr;
                for (int j=max(0,found-1); j<=found; j++) {
                    if (minval>abs(arr[i]+arr[j])) {
                        if (i!=j) {
                            minval = abs(arr[i]+arr[j]);
                            mina = i; minb = j;
                        }
                    }
                }
            }
        } else {
            for (int i=firstplus; i<N; i++) {
                int found = lower_bound(arr, arr+N, -arr[i]) - arr;
                for (int j=max(0,found-1); j<=found; j++) {
                    if (minval>abs(arr[i]+arr[j])) {
                        if (i!=j) {
                            minval = abs(arr[i]+arr[j]);
                            mina = j; minb = i;
                        }
                    }
                }
            }
        }
        cout<<arr[mina]<<" "<<arr[minb]<<endl;
    }
}