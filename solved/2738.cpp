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

int arr1[101][101];
int arr2[101][101];
void solve() {
    int Y, X; cin>>Y>>X;
    for (int y=0; y<Y; y++) {
        for (int x=0; x<X; x++) {
            cin>>arr1[y][x];
        }
    }
    for (int y=0; y<Y; y++) {
        for (int x=0; x<X; x++) {
            cin>>arr2[y][x];
        }
    }
    for (int y=0; y<Y; y++) {
        for (int x=0; x<X; x++) {
            cout<<arr1[y][x]+arr2[y][x]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}