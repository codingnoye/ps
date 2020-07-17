#include <iostream>
using namespace std;

int arr[1000001];
int val[1000001];
int rem[1000001];
int remi = 0;
int main() {
    int N, x, d; cin>>N;
    int len = 0;
    while (N--) {
        cin>>x;
        val[remi] = x;
        d = lower_bound(arr, arr+len, x) - arr;
        arr[d] = x;
        if (d>=len) len++;
        rem[remi++] = d;
    }
    cout<<len<<endl;
    int target = len-1;
    int res[len];
    for (int i=remi-1; i>=0; i--) {
        if (target<0) break;
        if (target == rem[i]) res[target--] = val[i];
    }
    for (int i=0; i<len; i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}