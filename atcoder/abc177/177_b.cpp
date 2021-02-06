#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    string S, T; cin>>S>>T;
    int mn = 100000;
    for (int i=0; i<S.length() - T.length() + 1; i++) {
        int hamd = 0;
        for (int j=0; j<T.length(); j++) {
            if (S.at(i+j) != T.at(j)) hamd++;
        }
        mn = min(hamd, mn);
    }
    cout<<mn;
}