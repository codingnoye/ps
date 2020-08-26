#include <iostream>
using namespace std;

int arr[1000][1000] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin>>N>>M;
    for (int y=0; y<N; y++) {
        for (int x=0; x<M; x++) {
            cin>>arr[y][x];
        }
    }
    for (int x=1; x<M; x++) {
        arr[0][x] = arr[0][x-1] + arr[0][x];
    }
    for (int y=1; y<N; y++) {
        arr[y][0] = arr[y-1][0] + arr[y][0];
    }
    for (int y=1; y<N; y++) {
        for (int x=1; x<M; x++) {
            arr[y][x] = max(arr[y-1][x], arr[y][x-1]) + arr[y][x];
        }
    }
    cout<<arr[N-1][M-1]<<endl;
}