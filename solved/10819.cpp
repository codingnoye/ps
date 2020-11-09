#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int N;
int val[9];
int selected[9];
int mabs(int x) {
    if (x<0) return -x;
    return x;
}
int mx = 0;
void backtrack(int i) {
    if (i==N) {
        int sm = 0;
        for (int j=0; j<N-1; j++) {
            sm += mabs(val[selected[j]]-val[selected[j+1]]);
        }
        mx = max(sm, mx);
    } else {
        for (int j=0; j<N; j++) {
            bool contain = false;
            for (int k=0; k<i; k++) if (selected[k] == j) {
                contain = true;
                break;   
            }
            if (contain) continue;
            selected[i] = j;
            backtrack(i+1);
        }
    }
}

void solve() {
    cin>>N;
    for (int i=0; i<N; i++) cin>>val[i];
    backtrack(0);
    cout<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}