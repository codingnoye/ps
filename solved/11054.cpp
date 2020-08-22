#include <iostream>
using namespace std;

int nums[1001];
int leftlen[1001] = {0};
int rightlen[1001] = {0};
int main() {
    int n; cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>nums[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (nums[i]<nums[j]) {
                int tmp = leftlen[i]+1;
                leftlen[j] = tmp>leftlen[j]?tmp:leftlen[j];
            }
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=i-1; j>=1; j--) {
            if (nums[i]<nums[j]) {
                int tmp = rightlen[i]+1;
                rightlen[j] = tmp>rightlen[j]?tmp:rightlen[j];
            }
        }
    }
    int mx = 0;
    int tmp;
    for (int i=1; i<=n; i++) {
        tmp = (leftlen[i]+rightlen[i]+1);
        if (mx<tmp) {
            mx = tmp;
        }
    }
    cout<<mx<<endl;
}