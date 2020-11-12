#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;


vector<char> chars;
int L, C;
int mo = 0;
int ja = 0;
vector<char> word;
bool ismo(char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

void step(int s, int d) {
    if (d==L) {
        if (mo>0 && ja>1) {
            string st(word.begin(), word.end());
            cout<<st<<endl;
        }
    } else {
        for (int i=s; i<chars.size(); i++) {
            word.push_back(chars[i]);
            bool im = ismo(chars[i]);
            if (im) mo++;
            else ja++;
            step(i+1, d+1);
            word.pop_back();
            if (im) mo--;
            else ja--;
        }
    }
}

void solve() {
    cin>>L>>C;
    for (int i=0; i<C; i++) {
        char x; cin>>x;
        chars.push_back(x);
    }
    sort(chars.begin(), chars.end());
    step(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}