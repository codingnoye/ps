#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE = 'z'-'a';
int arr[SIZE];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    while (N--) {
        for (int i=0; i<SIZE; i++) arr[i] = 0;
        int n; cin>>n;
        for (int j=0; j<n; j++) {
            string tmp; cin>>tmp;
            for (auto c: tmp) {
                arr[c-'a']++;
            }
        }
        bool can = true;
        for (int i=0; i<SIZE; i++) {
            if (arr[i]%n!=0) can = false;
        }
        cout<<(can?"YES":"NO")<<'\n';
    }
}