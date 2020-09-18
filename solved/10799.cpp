#include <iostream>
#include <stack>
using namespace std;

int main() {
    string inp; cin>>inp;
    int depth = 0;
    int count = 0;
    char last = 'X';
    for (char c: inp) {
        if (c=='(') {
            depth++;
        } else {
            if (last=='(') {
                count += --depth;
            } else {
                count++;
                depth--;
            }
        }
        last = c;
    }
    cout<<count<<endl;
}