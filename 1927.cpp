#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > pq;
    int n; cin>>n;
    int x;
    for (int c=0; c<n; c++) {
        cin>>x;
        if (x==0) {
            if (pq.empty()) cout<<0<<'\n';
            else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}