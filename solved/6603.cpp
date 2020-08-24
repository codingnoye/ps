#include <iostream>
#include <vector>
using namespace std;

int K;
int arr[14] = {0};
int history[6] = {0};

void dfs(int depth, int idx) {
    if (depth==6) {
        for (int i=0; i<6; i++) {
            cout<<arr[history[i]]<<' ';
        }
        cout<<'\n';
        return;
    }
    for (int i=idx; i<K; i++) {
        history[depth] = i;
        dfs(depth+1, i+1);
    }
}

int main() {
    while (true) {
        cin>>K;
        if (K==0) break;
        for (int i=0; i<K; i++) cin>>arr[i];
        dfs(0, 0);
        cout<<'\n';
    }
}