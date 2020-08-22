#include <iostream>
#include <cmath>
using namespace std;

bool dived[1000001] = {false};
long long nums[1000001] = {0};

int main() {
    int numi = 0;
    long long mn;
    long long mx;
    cin>>mn>>mx;
    long long smx = sqrt(mx);
    for (int i=2; i<=smx; i++) {
        nums[numi++] = (long long)i*i;
    }
    int cnt = mx-mn+1;
    long long tmp;
    for (int j=0; j<numi; j++) {
        cout<<mn<<" "<<nums[j]<<endl;
        if (mn%nums[j] == 0) tmp = mn;
        else tmp = ((mn/nums[j])+1)*nums[j];
        for (long long i = tmp; i<=mx; i+=nums[j]) {
            if (!dived[i-mn]) {
                dived[i-mn] = true;
                cnt--;
            }
        }
    }
    cout<<cnt<<endl;
}