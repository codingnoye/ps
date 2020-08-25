#include <iostream>
using namespace std;

int arr[1002][10] = {0};

int main() {
    int N; cin>>N;
    for (int i=0; i<10; i++) {
        arr[1][i] = 1;
    }
    for (int i=2; i<=1001; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<=j; k++) {
                arr[i][j] = (arr[i][j] + arr[i-1][k]) % 10007;
            }
        }
    }
    cout<<arr[N+1][9]<<endl;
}