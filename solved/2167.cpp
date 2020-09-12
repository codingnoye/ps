#include <iostream>
using namespace std;
int arr[301][301] = {0};
int main() {
    int N, M; cin>>N>>M;
    for (int y=1; y<=N; y++) {
        for (int x=1; x<=M; x++) {
            cin>>arr[y][x];
            arr[y][x] += arr[y-1][x];
            arr[y][x] += arr[y][x-1] - arr[y-1][x-1];
        }
    }
    int T; cin>>T;
    while (T--) {
        int i,j,x,y; cin>>j>>i>>y>>x;
        cout<<(arr[y][x] - arr[y][i-1] - arr[j-1][x] + arr[j-1][i-1])<<endl;
    }
}