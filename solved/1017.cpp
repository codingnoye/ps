#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sieve[4001];

int first;
bool firstOdd;
vector<int> leftNums;
vector<int> rightNums;

int owner[1001];
bool visited[1001];
const int EMPTY = 0;

bool matching(int left) {
    if (visited[left]) return false;
    visited[left] = true;
    for (int i=0; i<rightNums.size(); i++) {
        int R = rightNums[i];
        if (sieve[R+left]) continue;
        if (owner[R] == EMPTY || matching(owner[R])) {
            owner[R] = left;
            return true;
        }
    }
    return false;
}
int main() {
    // 에라토스테네스의 체
    for (int i=2; i<=2000; i++) {
        if (!sieve[i]) for (int j=i*2; j<=2000; j+=i) sieve[j] = true;
    }
    int N; cin>>N;
    for (int i=1; i<=N; i++) {
        int x; cin>>x;
        if (i==1) {
            first = x;
            if (x%2 == 1) firstOdd = true;
            else firstOdd = false;
        }
        if ((firstOdd && x%2==1) || (!firstOdd && x%2==0)) leftNums.push_back(x);
        else rightNums.push_back(x);
    }
    if (leftNums.size() != rightNums.size()) {
        cout<<"-1\n";
        return 0;
    }
    vector<int> res;
    for (int right: rightNums) {
        if (sieve[first+right]) continue;
        for (int j: rightNums) owner[j] = EMPTY;
        owner[right] = first;
        for (int i=1; i<leftNums.size(); i++) {
            int left = leftNums[i];
            for (int j: leftNums) visited[j] = false;
            visited[first] = true;
            matching(left);
        }
        int cnt = 0;
        for (int i: rightNums) {
            if (owner[i]) cnt++;
        }
        if (cnt == rightNums.size()) {
            res.push_back(right);
        }
    }
    if (res.size()==0) cout<<"-1";
    else {
        sort(res.begin(), res.end());
        for (int i: res) {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}