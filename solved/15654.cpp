#include <iostream>
#include <algorithm>
using namespace std;


void left_rotate(int* arr, int s, int e) {
    int start = arr[s];
    for (int i=s; i<e; i++) arr[i] = arr[i+1];
    arr[e] = start;
}
void right_rotate(int* arr, int s, int e) {
    int last = arr[e];
    for (int i=e; i>s; i--) arr[i] = arr[i-1];
    arr[s] = last;
}
void perm(int* arr, int depth, int n, int m) {
    if (depth == m) {
        for(int i=0; i<m; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for (int i = depth; i<n; i++) {
        right_rotate(arr, depth, i);
        perm(arr, depth+1, n, m);
        left_rotate(arr, depth, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; cin>>n>>m;
    int arr[n];
    for (int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n, less<int>());
    perm(arr, 0, n, m);
}