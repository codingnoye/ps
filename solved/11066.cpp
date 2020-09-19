#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int N;
int arr[502];
int sm[502];
ull dp[502][502];

const ull MAX = 40000000000000ULL;

int main() {
    int T; cin>>T;
    while (T--) {
        cin>>N;
        arr[0] = 0;
        sm[0] = 0;
        for (int i=1; i<=N; i++) {
            int x; cin>>x;
            arr[i] = x;
            sm[i] = sm[i-1]+x;
            dp[i][i] = 0;
        }
        for (int size=2; size<=N; size++) {
            for (int s=1; s+size-1<=N; s++) {
                dp[s][s+size-1] = MAX;
                //cout<<"dp["<<s<<"]["<<s+size-1<<"] start"<<endl;
                for (int e=s; e+1<=s+size-1; e++) {
                    dp[s][s+size-1] = min(dp[s][s+size-1], dp[s][e] + dp[e+1][s+size-1] + sm[s+size-1] - sm[s-1]);
                    //cout<<"dp["<<s<<"]["<<e<<"] + dp["<<e+1<<"]["<<s+size-1<<"]"<<endl;
                }
                //cout<<"dp["<<s<<"]["<<s+size-1<<"] is "<<dp[s][s+size-1]<<endl;
            }
        }
        cout<<dp[1][N]<<endl;
    }
}