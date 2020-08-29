#include <iostream>
using namespace std;

int main() {
    int T=3;
    while(T--) {
        int a, b, c, d, e, f; cin>>a>>b>>c>>d>>e>>f;
        int res = (d*3600+e*60+f) - (a*3600+b*60+c);
        cout<<(res/3600)<<" "<<(res%3600/60)<<" "<<(res%60)<<endl;
    }
}