#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int arr[1001];
void solve() {
    int N, K; cin>>N>>K;
    int cnt = 0;
    for (int i=2; i<=N; i++) {
        if (arr[i] == 0) {
            for (int j=i; j<=N; j+=i) {
                if (arr[j] == 0) {
                    if (++cnt == K) {
                        cout<<j<<endl;
                        break;
                    }
                    arr[j] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}