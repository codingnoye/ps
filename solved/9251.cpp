#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'

int length[1001][1001] = {0};

void solve() {
    string l1, l2; cin>>l1>>l2;
    for (int i=0; i<l1.size(); i++) {
        for (int j=0; j<l2.size(); j++) {
            if (l1.at(i)==l2.at(j)) {
                length[i+1][j+1] = length[i][j] + 1;
            } else {
                length[i+1][j+1] = max(length[i+1][j], length[i][j+1]);
            }
        }
    }
    cout<<length[l1.size()][l2.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}