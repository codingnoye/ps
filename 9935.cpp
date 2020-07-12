#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> stk;
string bomb;
int bomblen;
char trigger;
bool cmp() {
    for(int i=1; i<=bomb.length(); i++) {
        if (bomb.at(bomb.length()-i) != stk[stk.size()-i]) return false;
    }
    return true;
}
int main() {
    string s; cin>>s;
    cin>>bomb;
    bomblen = bomb.length();
    trigger = bomb.at(bomb.length()-1);
    for (char c: s) {
        stk.push_back(c);
        if (c == trigger) {
            if (stk.size()>=bomblen) {
                if (cmp()) {
                    for (int i=0; i<bomblen; i++) stk.pop_back(); 
                }
            }
        }
    }
    if (stk.empty()) cout<<"FRULA";
    else for (char c: stk) {
        cout<<c;
    }
    cout<<endl;
}