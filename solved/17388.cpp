#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3]; cin>>a[0]>>a[1]>>a[2];
    string st[3] = {"Soongsil", "Korea", "Hanyang"};
    if (a[0]+a[1]+a[2] < 100) {
        cout<<st[(min_element(a, a+3)-a)];
    } else cout<<"OK";
}