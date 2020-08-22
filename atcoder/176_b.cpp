#include <iostream>
using namespace std;

int main() {
    string IN; cin>>IN;
    int sm = 0;
    for (char c: IN) {
        sm += (int)(c-'0');
    }
    cout<<(sm%9==0?"Yes":"No")<<endl;
}