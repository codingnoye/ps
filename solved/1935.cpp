#include <iostream>
#include <stack>
using namespace std;

double vals[26] = {0};
int main() {
    int N; cin>>N;
    string str; cin>>str;
    for (int i=0; i<N; i++) cin>>vals[i];
    stack<double> st;
    for (auto c: str) {
        if ('A'<=c && c<='Z') {
            st.push(vals[c-'A']);
        } else {
            double B = st.top(); st.pop();
            double A = st.top(); st.pop();
            double res;
            if (c=='+') res = A+B;
            else if (c=='-') res = A-B;
            else if (c=='*') res = A*B;
            else res = A/B;
            st.push(res);
        }
    }
    printf("%.2f\n", st.top());
}