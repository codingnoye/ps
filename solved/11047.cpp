#include <iostream>
using namespace std;


int val[10];
int dfs(int left, int i) {
    int now = val[i];
    if (i==-1) {
        if (left==0) return 0;
        else return -1;
    }
    for (int count = (left+now-1)/now; count>=0; count--) {
        int tmp = dfs(left-count*now, i-1);
        if (tmp>=0) return tmp + count;
    }
    return -1;
}

int main() {
    int N, K; cin>>N>>K;
    for (int i=0; i<N; i++) cin>>val[i];
    cout<<dfs(K, N-1)<<endl;
}