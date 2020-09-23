#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
const int MAX = 100001;
int avails[MAX];

int avail(int x) {
    if (avails[x] == x) return x;
    return avails[x] = avail(avails[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int G, P; cin>>G>>P;
    for (int i=0; i<=G; i++) avails[i] = i;
    int res = 0;
    while (P--) {
        int x; cin>>x;
        int a = avail(x);
        if (a==0) break;
        avails[a] = a-1;
        res++;
    }
    cout<<res<<endl;
}