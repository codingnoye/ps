#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;
 
long double dp[200010];

const long double t = 10.0;
int main() {
    fastio;
    
    map<string,int> sti;
    int stin=0;
    int N; cin>>N;

    fill(dp,dp+200010,-987654321.0);
    
    sti["pink"]=stin++;
    sti["blue"]=stin++;
    dp[0]=0;
    for(int i=0;i<N;i++){
        string a,b;
        long double c;

        cin>>a>>b>>c;
        long double cl = log2(c);
        if(sti.count(a)==0) sti[a]=stin++;
        if(sti.count(b)==0) sti[b]=stin++;
        int ai=sti[a],bi=sti[b];
        dp[ai]=max(dp[ai],dp[bi]+cl);
    }
    cout<<fixed;
    cout.precision(15);
    cout<<min(t, dp[1]>-987000000?pow(2, dp[1]):0);
    return 0;
}