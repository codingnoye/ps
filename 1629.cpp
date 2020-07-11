#include <iostream>
using namespace std;

long long a, b, c;
long long solve(int exp) {
    if (exp%2==0) {
        long long tmp = solve(exp/2);
        return (tmp*tmp)%c;
    } else if (exp==1) {
        return a%c;
    } else {
        return ((a%c)*solve(exp-1))%c;
    }
}
int main() {
    cin>>a>>b>>c;
    cout<<solve(b)<<endl;
}