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

int N;

int trace[11];
int cnt;
int L=0;
void rc(int d) {
    trace[d]++;
    if (trace[d] > 9) {
        trace[d+1] = d+1;
        L = d+1;
        trace[d] = d;
    }
    else if (trace[d] >= trace[d+1] && trace[d+1] != -1) {
        trace[d] = d;
        rc(d+1);
    }
}

void solve() {
    cin>>N;
    if (N>1022) {
        cout<<-1<<endl;
        return;
    }
    for (int j=1; j<11; j++) {
        trace[j] = -1;
    }
    for (int j=0; j<N; j++) {
        rc(0);
    }
    for (int j=L; j>=0; j--) cout<<trace[j];
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
/*
1  1  1  1  1  1  1  1  1  1 
0  1  2  3  4  5  6  7  8  9 
0  0  1  3  6 10 15 21 28 36 
0  0  0  1  4 10 20 35 56 84 
0  0  0  0  1  5 15 35 70 126 
0  0  0  0  0  1  6 21 56 126 
0  0  0  0  0  0  1  7 28 84 
0  0  0  0  0  0  0  1  8 36 
0  0  0  0  0  0  0  0  1  9
0  0  0  0  0  0  0  0  0  1
*/