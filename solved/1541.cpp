#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin>>s; s+='+';
    string tmp = "";
    bool minused = false;
    int res = 0;
    for (int i=0; i<s.length(); i++) {
        char c = s.at(i);
        if (c=='+') {
            if (minused) res -= stoi(tmp);
            else res += stoi(tmp); 
            tmp = "";
        } else if (c=='-') {
            if (minused) res -= stoi(tmp);
            else res += stoi(tmp); 
            minused = true;
            tmp = "";
        } else {
            tmp += c;
        }
    }
    cout<<res<<endl;
}