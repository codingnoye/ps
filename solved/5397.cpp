#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

void solve() {
    int N; cin>>N;
    for (int _=0; _<N; _++) {
        string inp; cin>>inp;
        list<char> li;
        auto cur = li.begin();
        for (char c: inp) {
            if (c=='<') {
                if (cur != li.begin()) {
                    cur--;
                }
            } else if (c=='>') {
                if (cur != li.end()) {
                    cur++;
                }
            } else if (c=='-') {
                if (cur != li.begin()) {
                    cur--;
                    cur = li.erase(cur);
                }
            } else {
                cur = li.insert(cur, c);
                cur++;
            }
        }
        for (char c: li) cout<<c;
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}