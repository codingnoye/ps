#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int mabs(int x){
    if (x<0) return -x;
    return x;
}

int main() {
    int a, b, c, d, e, f, g, h; cin>>a>>b>>c>>d>>e>>f>>g>>h;
    int x = max(max(max(mabs(c-e), mabs(d-f)), max(mabs(g-a), mabs(h-b))), max(max(mabs(c-a), mabs(d-b)), max(mabs(g-e), mabs(h-f))));
    cout<<(x*x)<<endl;
}