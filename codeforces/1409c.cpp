#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;
int find(int x, int y, int n, int d) {
    int yisnth = (y-1)/d;
    int xisnth = (x-1)/d;
    int firstnth;
    int dist = yisnth - xisnth + 1;
    if (dist == n) {
        firstnth = xisnth;
    } else if (dist < n) {
        firstnth = yisnth - n + 1;
        if (firstnth<0) firstnth = 0;
    } else {
        return 1000000001;
    }
    int orgfirst = y - (yisnth*d);
    int first = orgfirst + d * firstnth;
    return first;
}
int main() {
    int T; cin>>T;
    while (T--) {
        int n, x, y; cin>>n>>x>>y;
        int dist = y-x;
        vector<int> dividers;
        for (int i=1; i<=dist; i++) {
            if (dist%i == 0) dividers.push_back(i);
        }
        ull mnlast = 1000000001;
        int mnfirst = 0;
        int mnd = 0;
        for (auto it=dividers.rbegin(); it!=dividers.rend(); it++) {
            int first = find(x, y, n, *it);
            ull last = first + (*it)*n;
            if (last < mnlast) {
                mnlast = last;
                mnfirst = first;
                mnd = *it;
            }
        }
        for (int i=0; i<n; i++) {
            cout<<((ull)mnfirst + (ull)mnd*i)<<" ";
        }
        cout<<'\n';
    }
}