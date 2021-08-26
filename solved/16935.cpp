#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

int arr[101][101];

int tmp[101][101];

void solve() {
    int M, N, R; cin>>M>>N>>R;
    for (int y=0; y<M; y++) {
        for (int x=0; x<N; x++) {
            cin>>arr[y][x];
        }
    }
    while (R--) {
        int X; cin>>X;
        if (X == 1) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    arr[y][x] = tmp[M-y-1][x];
                }
            }
        } else if (X == 2) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    arr[y][x] = tmp[y][N-x-1];
                }
            }
        } else if (X == 3) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            swap(N, M);
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    arr[y][x] = tmp[N-x-1][y];
                }
            }
        } else if (X == 4) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            swap(N, M);
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    arr[y][x] = tmp[x][M-y-1];
                }
            }
        } else if (X == 5) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            for (int y=0; y<M/2; y++) {
                for (int x=0; x<N/2; x++) {
                    arr[y][x+N/2] = tmp[y][x];
                }
            }
            for (int y=0; y<M/2; y++) {
                for (int x=N/2; x<N; x++) {
                    arr[y+M/2][x] = tmp[y][x];
                }
            }
            for (int y=M/2; y<M; y++) {
                for (int x=N/2; x<N; x++) {
                    arr[y][x-N/2] = tmp[y][x];
                }
            }
            for (int y=M/2; y<M; y++) {
                for (int x=0; x<N/2; x++) {
                    arr[y-M/2][x] = tmp[y][x];
                }
            }
        }
        else if (X == 6) {
            for (int y=0; y<M; y++) {
                for (int x=0; x<N; x++) {
                    tmp[y][x] = arr[y][x];
                }
            }
            for (int y=0; y<M/2; y++) {
                for (int x=0; x<N/2; x++) {
                    arr[y][x] = tmp[y][x+N/2];
                }
            }
            for (int y=0; y<M/2; y++) {
                for (int x=N/2; x<N; x++) {
                    arr[y][x] = tmp[y+M/2][x];
                }
            }
            for (int y=M/2; y<M; y++) {
                for (int x=N/2; x<N; x++) {
                    arr[y][x] = tmp[y][x-N/2];
                }
            }
            for (int y=M/2; y<M; y++) {
                for (int x=0; x<N/2; x++) {
                    arr[y][x] = tmp[y-M/2][x];
                }
            }
        }
    }
    for (int y=0; y<M; y++) {
        for (int x=0; x<N; x++) {
            cout<<arr[y][x]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}