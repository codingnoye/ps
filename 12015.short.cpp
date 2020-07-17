#include<iostream>
using namespace std;int A[1000001];main(){int N,x,d,L=0;cin>>N;while(N--){cin>>x;d=lower_bound(A,A+L,x)-A;if(d<L)A[d]=x;else A[L++]=x;}cout<<L;}