#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int a, b, c; cin>>a>>b>>c;
        if (!(a||b||c)) break;
        int mx = max(max(a, b), c);
        cout<<(mx*mx*2==a*a+b*b+c*c?"right":"wrong")<<endl;
    }
}