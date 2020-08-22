#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "";
    while (true) {
        cin>>s;
        if (s=="0") break;
        bool t = true;
        for (int i=0; i<s.length()/2 && t; i++) if (s.at(i) != s.at(s.length()-1-i)) t = false;
        cout<<(t?"yes":"no")<<endl;
    }
}