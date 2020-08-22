#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
const ull M = 1000000000ULL;
typedef vector<vector<ull>> matrix;
matrix operator * (const matrix &A, const matrix &B) {
    matrix R = {{(A[0][0]*B[0][0]+A[0][1]*B[1][0])%M, (A[0][0]*B[0][1]+A[0][1]*B[1][1])%M}, 
                {(A[1][0]*B[0][0]+A[1][1]*B[1][0])%M, (A[1][0]*B[0][1]+A[1][1]*B[1][1])%M}};
    return R;
}
ull get_fibo(ull n) {
    matrix res = {{1, 0}, {0, 1}};
    matrix now = {{1, 1}, {1, 0}};
    while (n>0) {
        if (n%2 == 1) {
            res = res * now;
        }
        now = now * now;
        n>>=1;
    }
    return res[0][1];
}
int main() {
    ull a, b; cin>>a>>b;
    cout<<((get_fibo(b+2)-get_fibo(a+1)+M)%M)<<endl;
}