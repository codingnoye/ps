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

vector<ii> nodes;

void solve() {
    int T; cin>>T;
    while (T--) {
        int N; cin>>N;
        nodes.clear();
        nodes.resize(N);
        unsigned long long total = 0;
        for (int i=0; i<N; i++) {
            int x; cin>>x;
            nodes[i] = make_pair(x, 0);
            total += x;
        }
        for (int i=0; i<N-1; i++) {
            int a, b; cin>>a>>b;
            nodes[a-1].second++;
            nodes[b-1].second++;
        }
        sort(nodes.begin(), nodes.end());
        cout<<total<<" ";
        int k = 2;
        for (auto it=nodes.rbegin(); it!=nodes.rend(); it++) {
            while (it->second > 1 && k<N) {
                it->second -= 1;
                total += it->first;
                k++;
                cout<<total<<" ";
            }
            if (k>=N) break;
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