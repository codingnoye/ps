#include <iostream>
using namespace std;

int* score;
int* dp;
int n;

int main() {
    cin>>n;
    score = new int[n];
    dp = new int[n];
    for (int i=0; i<n; i++) {
        cin>>score[i];
        dp[i] = 0;
    }
    dp[1] = score[0];
    dp[2] = score[0] + score[1];
    int score1;
    int score2;
    for (int i=3; i<n; i++) {
        score1 = dp[i-2] + score[i-1];
        score2 = dp[i-3] + score[i-2] + score[i-1];
        dp[i] = score1>score2?score1:score2;
    }
    int res1 = n>1?dp[n-2]+score[n-1]:score[n-1];
    int res2 = n>1?dp[n-3]+score[n-2]+score[n-1]:0;
    cout<<(res1>res2?res1:res2)<<endl;
}