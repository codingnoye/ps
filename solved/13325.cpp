#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int input[4100000]={0,};
int t[4100000]={0,};
int maxSum=0;
int k;
int maxIndex=0;
int result=0;

void funcSum(int index, int sum)
{
    if(sum> maxSum)
    {
        maxSum=sum;
    }

    if(index >= maxIndex)
    {
        return;
    }
    t[index] = sum+input[index];
    funcSum(index*2, sum+input[index]);
    funcSum(index*2+1, sum+input[index]);
}

int funcResult(int index)
{
    int l = index*2;
    int r= index*2+1;

    if((1<<k) <= l && l < maxIndex  )
    {
        int m=min(maxSum-t[l], maxSum-t[r]);
        result+=maxSum-t[l]-m;
        result+=maxSum-t[r]-m;
        return m;
    }

    int a = funcResult(l);
    int b = funcResult(r);
    int m = min(a,b);
    result+=a-m;
    result+=b-m;
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    maxIndex= (1<<(k+1));

    for(int i=1 ; i<=k ; i++)
    {
        int a=1<<i;
        for(int j=a ; j<a*2 ; j++)
        {
            cin>>input[j];
            result+=input[j];
        }
    }
    funcSum(1,0);
    funcResult(1);

    cout<<result;
}