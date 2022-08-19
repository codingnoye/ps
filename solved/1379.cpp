#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

vector<pair<pair<int, int>, int>> classes; // (start, end), idx

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> original_order(N);
    for (int i=0; i<N; i++) {
        int id, start, end; cin>>id>>start>>end;
        classes.push_back({{start, end}, id-1});
    }
    sort(classes.begin(), classes.end());

    vector<int> results(N, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // endtime, idx
    int K = 1;
    pq.push({0, 1});
    for (int i=0; i<classes.size(); i++) {
        auto [start, end] = classes[i].first;
        int id = classes[i].second;
        // cout<<"id: "<<id<<endl;
        if (pq.empty()) {
            pq.push({end, ++K});
            results[id] = K;
        } else {
            auto [endtime, room_idx] = pq.top();
            if (endtime <= start) {
                pq.pop();
                pq.push({end, room_idx});
                results[id] = room_idx;
            } else {
                pq.push({end, ++K});
                results[id] = K;
            }
        }
    }
    cout<<K<<endl;
    for (auto result : results) {
        cout<<result<<endl;
    }
}