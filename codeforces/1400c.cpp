#include <iostream>
#include <string>
using namespace std;

int arr[100001];
bool iszero[100001];
int main() {
    int T; cin>>T;
    while (T--) {
        string S; cin>>S;
        int N; cin>>N;
        int L = S.length();
        fill_n(arr, L+1, 0);
        fill_n(iszero, L+1, false);
        for (int i=0; i<L; i++) {
            if (S.at(i) == '0') {
                if (i-N >= 0) iszero[i-N] = true;
                if (i+N < L) iszero[i+N] = true;
            }
        }
        bool used;
        for (int i=0; i<L; i++) {
            if (S.at(i) == '1') {
                used = false;
                if (i-N>=0) {
                    if (!iszero[i-N]) {
                        used = true;
                        arr[i-N] = 1;    
                    }
                }
                if (i+N<L) {
                    if (!iszero[i+N]) {
                        used = true;
                        arr[i+N] = 1;
                    }
                }
                if (!used) {
                    cout<< -1 <<'\n';
                    break;
                }
            }
        }
        if (used) {
            for (int i=0; i<L; i++) {
                cout<<arr[i];
            }
            cout<<'\n';
        }
    }
}