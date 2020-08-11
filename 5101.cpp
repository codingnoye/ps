#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    while (!(a==0 && b==0 && c==0)) {
        if ((c-a)%b==0 && a<=c) {
            cout<<((c-a)/b+1)<<'\n';
        } else {
            cout<<"X\n";
        }
        cin>>a>>b>>c;
    }
}