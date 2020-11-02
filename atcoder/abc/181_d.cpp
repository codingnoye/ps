#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull, ull> ll;

int cnt[10];
int even, odd;

void solve() {
    string S; cin>>S;
    for (char c: S) {
        int now = c-'0';
        cnt[now]++;
        if (now%2 == 0) even++;
        else odd++;
    }
    if (S.length() == 1) {
        if (S == "8") {
            cout<<"Yes"<<endl;
            return;
        }
    } else if (S.length() == 2) {
        int a = S.at(0) - '0';
        int b = S.at(1) - '0';
        if (((a*10+b)%8 == 0) || (b*10+a)%8 == 0) {
            cout<<"Yes"<<endl;
            return;
        }
    } else if (
        (cnt[1]>0 && cnt[6]>0 && even>=2) ||
        (cnt[2]>0 && cnt[4]>0 && even>=3) ||
        (cnt[3]>0 && cnt[2]>0 && even>=2) ||
        (cnt[4]>0 && cnt[8]>0 && even>=3) ||
        (cnt[5]>0 && cnt[6]>0 && even>=2) ||
        (cnt[6]>0 && cnt[4]>0 && even>=3) ||
        (cnt[7]>0 && cnt[2]>0 && even>=3) ||
        (cnt[8]>1 & even>=3) ||
        (cnt[9]>0 && cnt[6]>0 && even>=2) ||
        (cnt[1]>0 && cnt[2]>0 && odd>=2) ||
        (cnt[2]>0 && cnt[8]>0 && odd>=1) ||
        (cnt[3]>0 && cnt[6]>0 && odd>=2) ||
        (cnt[4]>1 && odd>=1) ||
        (cnt[5]>0 && cnt[2]>0 && odd>=2) ||
        (cnt[6]>0 && cnt[8]>0 && odd>=1) ||
        (cnt[7]>0 && cnt[6]>0 && odd>=2) ||
        (cnt[8]>0 && cnt[4]>0 && odd>=1) ||
        (cnt[9]>0 && cnt[2]>0 && odd>=1)
    ) {
        cout<<"Yes"<<endl;
        return;
    }

    cout<<"No"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}