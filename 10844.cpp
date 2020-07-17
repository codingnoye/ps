#include <iostream>
using namespace std;
const int MAX = 1e9;
int arr[101][10] = {0};
int main() {
    int n; cin>>n;
    for (int j=1; j<=9; j++) arr[1][j] = 1;
    for (int i=2; i<=n; i++) {
        arr[i][0] = arr[i-1][1];
        arr[i][9] = arr[i-1][8];
        for (int j=1; j<=8; j++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % MAX;
        }
    }
    int sum = 0;
    for (int j=0; j<10; j++) {
        sum = (sum + arr[n][j]) % MAX;
    }
    cout<<sum<<endl;
}