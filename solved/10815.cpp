#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    for (int i=0; i<N; i++) cin>>arr[i];
    sort(arr, arr+N);
    int K; cin>>K;
    for (int i=0; i<K; i++) {
        int x; cin>>x;
        cout<<(binary_search(arr, arr+N, x)?1:0)<<' ';
    }
}