#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    int T; cin>>T;
    while (T--) {
        int a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        int res = max(a+e,1) + 5 * max(b+f,1) + 2 * max(c+g,0) + 2 * (d+h);
        cout<<res<<endl; 
    }
}