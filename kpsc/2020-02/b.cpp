#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int LOGIN = 1;
const int LOGOUT = 0;

bool cmp(ii A, ii B) {
    if (A.first==B.first) {
        return A.second>B.second;
    }
    return A.first<B.first;
}

int main() {
    int N; cin>>N;
    vector<ii> V;
    for (int _=0; _<N; _++) {
        int I, O; cin>>I>>O;
        V.push_back(make_pair(I, LOGIN));
        V.push_back(make_pair(O, LOGOUT));
    }
    sort(V.begin(), V.end(), cmp);
    int mx = 0;
    int now = 0;
    for (auto it=V.begin(); it!=V.end(); it++) {
        if ((*it).second == LOGIN) {
            mx = max(mx, ++now);
        } else {
            now--;
        }
    }
    cout<<mx<<endl;
}