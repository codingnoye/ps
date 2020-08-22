#include <iostream>
using namespace std;

int arr[1000001];
int main() {
    int N, x, d; cin>>N;
    int len = 0;
    while (N--) {
        cin>>x;
        d = lower_bound(arr, arr+len, x) - arr;
        if (d<len) arr[d] = x;
        else arr[len++] = x;
    }
    cout<<len<<endl;
}