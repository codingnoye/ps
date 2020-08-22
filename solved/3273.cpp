#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;
    int arr[N];
    for (int i=0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N);
    int X; cin>>X;
    int cnt = 0;
    for (int i=0; i<N; i++) {
        if (binary_search(arr, arr+N, X-arr[i])) {
            cnt++;
        }
    }
    cout<<(cnt/2)<<endl;
}