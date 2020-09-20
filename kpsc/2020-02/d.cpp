#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<double, int> di;
//nowlen, index

int len[200001] = {0};
int slice[200001] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin>>N>>K;
    priority_queue<di> pq;
    for (int i=0; i<N; i++) {
        cin>>len[i];
        slice[i] = 1;
        pq.push(make_pair((double)len[i], i));
    }
    int i=0;
    while (i<K) {
        di now = pq.top(); pq.pop();
        int newslice = max(min((int)ceil((double)len[now.second]/pq.top().first) - slice[now.second], K), slice[now.second]+1);
        int delta = newslice - slice[now.second];
        i+=delta;
        slice[now.second] = newslice;
        pq.push(make_pair((double)len[now.second]/(newslice), now.second));
    }
    cout<<(rint(pq.top().first))<<endl;
}