#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<string> in_cars(N);
    for (int i=0; i<N; i++) cin>>in_cars[i];

    set<string> over;
    int j=0;
    for (int i=0; i<N; i++) {
        string now; cin>>now;
        while (over.find(in_cars[j]) != over.end()) j++;
        if (in_cars[j] != now) {
            over.insert(now);
        } else j++;
    }
    cout<<over.size()<<endl;
}