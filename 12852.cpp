#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1000001] = {0};
int main() {
    int N; cin>>N;
    queue<vector<int> > q;
    vector<int> x = {N}; 
    q.push(x);
    while (true) {
        int last = q.front().at(q.front().size()-1);
        if (last==0) {
            q.pop();
            continue;
        }
        if (last==1) {
            cout<<(q.front().size()-1)<<endl;
            for (auto i: q.front()) cout<<i<<" ";
            cout<<endl;
            break;
        }
        vector<int> a = q.front(); a.push_back(last/3);
        vector<int> b = q.front(); b.push_back(last/2);
        vector<int> c = q.front(); c.push_back(last-1);
        if (last%3 == 0) q.push(a);
        if (last%2 == 0) q.push(b);
        q.push(c);
        q.pop();
    }
}