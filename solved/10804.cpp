#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int arr[21];

void reverse(int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverse(start+1, end-1);
}

void solve() {
    for (int i=1; i<21; i++) {
        arr[i] = i;
    }
    for (int _=0; _<10; _++) {
        int a, b; cin>>a>>b;
        reverse(a, b);
    }
    for (int i=1; i<21; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}