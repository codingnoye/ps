#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

vector<ii> V;
bool arr[2001][2001];

void solve() {
    int N; cin>>N;
    for(int i=0; i<N; i++) {
        int a, b; cin>>a>>b;
        V.push_back(ii{a, b});
        arr[1000+a][1000+b] = true;
    }
    for (int i=0; i<N-2; i++) {
        int x0 = V[i].first;
        int y0 = V[i].second;
        for (int j=i+1; j<N-1; j++) {
            int x1 = V[j].first;
            int y1 = V[j].second;
            for (int k=j+1; k<N; k++) {
                int x2 = V[k].first;
                int y2 = V[k].second;
                if ((y1-y0)*(x2-x1) == (x1-x0)*(y2-y1)) {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}