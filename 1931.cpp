#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (pair<int, int> t1, pair<int, int> t2) {
    if (t1.second==t2.second) return (t1.first<t2.first);
    return (t1.second<t2.second);
}
int main() {
    int N; cin>>N;
    vector<pair<int, int> > v;
    for (int i=0; i<N; i++) {
        int s, e; cin>>s>>e;
        v.push_back(make_pair(s, e));
    }
    sort(v.begin(), v.end(), cmp);
    int lastend = 0;
    int cnt = 0;
    for (auto i: v) {
        if (i.first>=lastend) {
            lastend = i.second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}