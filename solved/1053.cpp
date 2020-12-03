#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
pair<int, int> stack[500001]; // value, ammount
int sp=0;
void solve() {
    int N; cin>>N;
    unsigned long long res = 0;
    int x; cin>>x;
    stack[sp++] = {x, 1};
    for (int i=1; i<N; i++) {
        int x; cin>>x;
        for (int i = sp-1; i>=0; i--) {
            if (stack[i].first < x) {
                sp--;
                res+=stack[i].second;
                //cout<<stack[i].first<<", "<<x<<endl;
            } else if (stack[i].first > x) {
                res++;
                //cout<<stack[i].first<<", "<<x<<endl;
                break;
            } else {
                res+=stack[i].second;
                //for (int _=0; _<stack[i].second; _++) cout<<stack[i].first<<", "<<x<<endl;
            }
        }
        if (stack[sp-1].first == x) stack[sp-1].second++;
        else stack[sp++] = {x, 1};
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}