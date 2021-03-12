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

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) > abs(b)) return true;
        else if (abs(a) < abs(b)) return false;
        else return a>b;
    }
};

void solve() {
    priority_queue<int, vector<int>, cmp> pq;
    int N; cin>>N;
    while (N--) {
        int x; cin>>x;
        if (x==0) {
            if (pq.size() == 0) {
                cout<<0<<endl;
            } else {
                cout<<pq.top()<<endl;
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}