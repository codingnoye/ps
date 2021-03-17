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

int arr[102][102];
int W, H, N;

void put(int sy, int sx, int ey, int ex, int n) {
    for (int y=sy; y<ey; y++) {
        for (int x=sx; x<ex; x++) {
            arr[y][x] = n;
        }
    }
}

int v[101];
void cnt() {
    for (int y=0; y<=101; y++) {
        for (int x=0; x<=101; x++) {
            v[arr[y][x]]++;
        }
    }
}

void solve() {
    cin>>N;
    for (int i=1; i<=N; i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        put(a,b,a+c,b+d,i);
    }
    cnt();
    for (int i=1; i<=N; i++) cout<<v[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}