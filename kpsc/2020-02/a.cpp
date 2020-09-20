#include <iostream>
using namespace std;

int main() {
    int T; cin>>T;
    while (T--) {
        string S; cin>>S;
        int X = 1;
        for (int i=0; i<S.length()-1; i++) X*=10;
        for (char c: S) {
            cout<<((c-'0')*X)<<' ';
            X/=10;
        }
        cout<<'\n';
    }
}