#include <iostream>
#include <algorithm>
using namespace std;
int abs(int a) {
    return a<0?-a:a;
}
int main() {
    int bx, by;
    int dx, dy;
    int jx, jy;
    cin>>bx>>by>>dx>>dy>>jx>>jy;
    bx = abs(bx-jx);
    by = abs(by-jy);
    dx = abs(dx-jx);
    dy = abs(dy-jy);
    int bdis = bx+by-min(bx,by);
    int ddis = dx+dy;
    if (bdis<ddis) cout<<"bessie"<<endl;
    else if (bdis>ddis) cout<<"daisy"<<endl;
    else cout<<"tie"<<endl;
}