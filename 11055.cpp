#include <iostream>
using namespace std;

int nums[1001];
int val[1001] = {0};
int main() {
    int n; cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>nums[i];
        val[i] = nums[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (nums[i]<nums[j]) {
                int tmp = val[i]+nums[j];
                val[j] = tmp>val[j]?tmp:val[j];
            }
        }
    }
    int mx = 0;
    for (int i=1; i<=n; i++) {
        if (mx<val[i]) {
            mx = val[i];
        }
    }
    cout<<mx<<endl;
}