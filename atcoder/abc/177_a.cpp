#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int D, T, S; cin>>D>>T>>S;
    cout<<(D <= S*T?"Yes":"No")<<endl;
}