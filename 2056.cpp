#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int main() {
    int time = 0;
    int N; cin>>N;
    vector<vector<int> > afters;
    int needs[N+1];
    int delay[N+1];
    afters.resize(N+1);
    needs[0] = 0;
    delay[0] = 0;
    for (int i=1; i<=N; i++) {
        needs[i] = 0;
        cin>>delay[i];
        int K; cin>>K;
        for (int k=0; k<K; k++) {
            int a; cin>>a;
            afters[a].push_back(i);
            needs[i]++;
        }
        afters[i].push_back(0);
        needs[0]++;
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for (int i=1; i<=N; i++) {
        if (needs[i]==0) {
            pq.push(make_pair(delay[i], i));
        }
    }
    while (!pq.empty()) {
        ii now = pq.top();
        pq.pop();
        time = now.first;
        if (now.second==0) break;
        for (auto it=afters[now.second].begin(); it!=afters[now.second].end(); it++) {
            if (--needs[*it] == 0)
                pq.push(make_pair(time+delay[*it], *it));
        }
    }
    cout<<time<<endl;
}